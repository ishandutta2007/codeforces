namespace Solution {
    open Microsoft.Quantum.Arithmetic;
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Math;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Diagnostics;
    open Microsoft.Quantum.Convert;

    operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        mutable r0=One;
        mutable r1=One;
        using(p=Qubit[2]) {
            H(p[0]); CNOT(p[0],p[1]);
            unitary(p[0]);
            CNOT(p[0],p[1]); H(p[0]);
            set r0=M(p[0]); set r1=M(p[1]);
            ResetAll(p);
        }
        if(r0==Zero) {
            if(r1==Zero) {return 0;}
            return 1;
        }
        if(r1==Zero) {return 3;}
        return 2;
    }
}