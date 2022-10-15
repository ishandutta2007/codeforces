namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Measurement;
 
    operation Solve (unitary : (Qubit[] => Unit is Adj+Ctl)) : Int {
        // your code here
        mutable r=1;
        using(q=Qubit[2]) {
            X(q[0]);
            unitary(q);
            if(MResetZ(q[1])==One) {
            set r=0;
            }
            Reset(q[0]);
            
        }
        return r;
    }
}