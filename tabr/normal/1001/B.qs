namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[], index : Int) : ()
    {
        body
        {
            if(index<2){
                if(index%2==1){
                    X(qs[0]);
                }
                H(qs[0]);
                CNOT(qs[0],qs[1]);   
            }else{
                if(index%2==1){
                    X(qs[0]);
                }
                H(qs[0]);
                X(qs[1]);
                CNOT(qs[0],qs[1]); 
            }
        }
    }
}