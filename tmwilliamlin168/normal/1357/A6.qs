namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Measurement;
    open Microsoft.Quantum.Math;
    open Microsoft.Quantum.Convert;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Arithmetic;
    open Microsoft.Quantum.Diagnostics;
    open Microsoft.Quantum.Arrays;
 
    operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        mutable r=0;
        using(q=Qubit[2]) {
            within {
                H(q[0]);
                CNOT(q[0], q[1]);
                X(q[1]);
            } apply {
                unitary(q[1]);
            }
            let a=MResetZ(q[0]);
            let b=MResetZ(q[1]);
            if(a==Zero&&b==One) {
            set r=1;
            } elif(a==One&&b==One) {
            set r=2;
            } elif(a==One&&b==Zero) {
            set r=3;
            }
        }
        return r;
    }
}