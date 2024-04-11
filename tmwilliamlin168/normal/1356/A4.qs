namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Measurement;
 
    operation Solve (unitary : (Qubit[] => Unit is Adj+Ctl)) : Int {
        mutable res=1;
        using(q=Qubit[2]) {
            unitary(q);
            if(MResetZ(q[1])==One) {
                set res=0;
            }
        }
        return res;
    }
}