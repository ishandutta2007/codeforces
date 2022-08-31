namespace Solution {
    open Microsoft.Quantum.Intrinsic;

    operation Solve (unitary : (Qubit[] => Unit is Adj+Ctl)) : Int {
        mutable res=One;
        using(s=Qubit[2]) {
            X(s[0]);
            X(s[1]);
            unitary(s);
            set res=M(s[0]);
            ResetAll(s);
        }
        if(res==One) {return 0;}
        return 1;
    }
}