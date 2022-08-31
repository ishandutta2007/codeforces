namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Diagnostics;
    open Microsoft.Quantum.Convert;
 
    operation Solve (unitary : ((Double, Qubit) => Unit is Adj+Ctl)) : Int {
        mutable res=One;
        using(x=Qubit[2]) {
            H(x[0]);
            CNOT(x[0],x[1]);
//            (Controlled R)([x[0]], (PauliZ, -6.283185307179586, x[1]));
            (Controlled unitary)([x[0]],(6.283185307179586,x[1]));
            CNOT(x[0],x[1]);
            H(x[0]);
//            DumpRegister("test.txt",x);
            set res=M(x[0]);
            ResetAll(x);
        }
        if(res==One) {return 0;}
        return 1;
    }
}