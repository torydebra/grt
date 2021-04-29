#ifndef GRT_CIRCULAR_BUFFER_MATRIX_FLOAT_HEADER
#define GRT_CIRCULAR_BUFFER_MATRIX_FLOAT_HEADER

#include "CircularBuffer.h"
#include "../DataStructures/MatrixFloat.h"

GRT_BEGIN_NAMESPACE

class CircularBufferMatrixFloat : public CircularBuffer<VectorFloat> {
    
public:
    
    using CircularBuffer::CircularBuffer;
    
    
    /**
     Gets the data in the CircularBuffer's internal buffer as a GRT::MatrixFloat
     
     @return returns a MatrixFloat with the data in the buffer, from the oldest inserted to the last inserted
     */
    MatrixFloat getDataAsMatrixFloat( ) const{
        
        if( bufferInit && numValuesInBuffer != 0){
            //Here we return only valid elements and in order from oldest to newest

            MatrixFloat data( numValuesInBuffer, this->buffer.at(0).getSize());
            for(unsigned int i=0; i<numValuesInBuffer; i++){
                

                if (! data.setRowVector((*this)[i], i)) {
                    errorLog << "Some error happened when inserting the "<< i << "th row" << std::endl;

                    return MatrixFloat();

                }
            }
            return data;
            
        }
        return MatrixFloat();
    }
    
    
};


GRT_END_NAMESPACE

#endif //GRT_CIRCULAR_BUFFER_MATRIX_FLOAT_HEADER
