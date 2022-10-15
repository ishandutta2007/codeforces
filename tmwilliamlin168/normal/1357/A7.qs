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
        mutable res=0;
        using(q=Qubit[2]) {
            H(q[0]);
            CNOT(q[0], q[1]);
            Controlled unitary(q[0..0], q[1]);
            Controlled unitary(q[0..0], q[1]);
            CNOT(q[0], q[1]);
            H(q[0]);
            if(MResetZ(q[0])==Zero) {
                //Y
                H(q[0]);
                CNOT(q[0], q[1]);
                Controlled unitary(q[0..0], q[1]);
                Controlled Adjoint Y(q[0..0], q[1]);
                CNOT(q[0], q[1]);
                H(q[0]);
                if(MResetZ(q[0])==One) {
                    set res=2;
                }
            } else {
                //XZ
                H(q[0]);
                CNOT(q[0], q[1]);
                Controlled unitary(q[0..0], q[1]);
                Controlled Adjoint X(q[0..0], q[1]);
                Controlled Adjoint Z(q[0..0], q[1]);
                CNOT(q[0], q[1]);
                H(q[0]);
                if(MResetZ(q[0])==One) {
                    set res=1;
                } else {
                    set res=3;
                }
            }
            ResetAll(q);
        }
        return res;
    }
}