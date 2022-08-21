namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Convert;

    operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        mutable w=One;
        using(s=Qubit[2]) {
            //make a bell state
            H(s[0]);
            CNOT(s[0],s[1]);
            (Controlled Z)([s[0]],s[1]);
            (Controlled unitary)([s[0]],s[1]);
            CNOT(s[0],s[1]);
            H(s[0]);
            set w=M(s[0]);
            if(w==One) {X(s[0]);}
            if(M(s[1])==One) {X(s[1]);}
        }
        if(w==One) {return 1;}
        return 0;
    }
}