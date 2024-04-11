namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Measurement;
 
    operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        mutable res=0;
        using(q=Qubit()) {
            H(q);
            unitary(q);
            unitary(q);
            H(q);
            if(MResetZ(q)==One) {
                set res=1;
            }
        }
        return res;
    }
}