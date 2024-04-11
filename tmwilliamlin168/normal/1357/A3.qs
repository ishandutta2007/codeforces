namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Measurement;
 
    operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        // your code here
        mutable r=0;
        using(q=Qubit()) {
            unitary(q);
            Z(q);
            unitary(q);
            if(MResetZ(q)==Zero) {
            set r=1;
            }
        }
        return r;
    }
}