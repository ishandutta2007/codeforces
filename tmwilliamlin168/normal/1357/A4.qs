namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Measurement;
    open Microsoft.Quantum.Math;
 
    operation Solve (unitary : ((Double, Qubit) => Unit is Adj+Ctl)) : Int {
        // your code here
        mutable r=0;
        using(q=Qubit[2]) {
            H(q[0]);
            Controlled unitary(q[0..0], (2.0*PI(), q[1]));
            H(q[0]);
            if(M(q[0])==Zero) {
            set r=1;
            }
            ResetAll(q);
        }
        return r;
    }
}