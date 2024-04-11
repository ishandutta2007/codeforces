namespace Solution {
    open Microsoft.Quantum.Arithmetic;
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Math;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Diagnostics;
    open Microsoft.Quantum.Convert;
 
    operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        mutable m0=One;
        mutable m1=One;
        using(p=Qubit[2]) {
            H(p[0]);
            CNOT(p[0],p[1]);
            (Controlled unitary)([p[0]],p[1]);
            (Controlled unitary)([p[0]],p[1]);
            CNOT(p[0],p[1]);
            H(p[0]);
            set m0=M(p[0]);
            ResetAll(p);
            H(p[0]);
            (Controlled Rx)([p[0]],(1.5707963267948966192313216916398,p[1]));
            if(m0==One) {(Controlled X)([p[0]],p[1]);(Controlled Z)([p[0]],p[1]);}
            (Controlled unitary)([p[0]],p[1]);
            (Controlled Rx)([p[0]],(-1.5707963267948966192313216916398,p[1]));
            H(p[0]);
            set m1=M(p[0]);
            ResetAll(p);
        }
        if(m0==Zero) {
            if(m1==Zero) {return 2;}
            return 0;
        }
        if(m1==Zero) {return 3;}
        return 1;
    }
}