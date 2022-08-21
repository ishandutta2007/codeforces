namespace Solution {
    open Microsoft.Quantum.Intrinsic;
 
    operation Solve (unitary : (Qubit[] => Unit is Adj+Ctl)) : Int {
        mutable res0=One;
        mutable res1=One;
        mutable res2=One;
        using(s=Qubit[2]) {
            X(s[0]);
            X(s[1]);
            unitary(s);
            set res0=M(s[0]);
            set res1=M(s[1]);
            X(s[1]);
            unitary(s);
            set res2=M(s[0]);
            ResetAll(s);
        }
        if(res0==Zero) {return 2;}
        if(res1==Zero) {return 1;}
        if(res2==One) {return 0;}
        return 3;
    }
}