namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
 
    operation Solve (x : Qubit[], y : Qubit) : Unit {
        body (...) {
            let n = Length(x);
            for(i in 0 .. n - 1){
                if((i &&& 1) == 1){
                    X(x[i]);
                }
            }
            Controlled X(x, y);
            for(i in 0 .. n - 1){
                X(x[i]);
            }
            Controlled X(x, y);
            for(i in 0 .. n - 1){
                if((i &&& 1) == 0){
                    X(x[i]);
                }
            }
        }
        adjoint auto;
    }
}