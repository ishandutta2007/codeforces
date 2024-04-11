namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Convert;

    operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        mutable w=One;
        using(s=Qubit()) {
            H(s);
            unitary(s);
            unitary(s);
            H(s);
            set w=M(s);
            if(w==One) {X(s);}
        }
        if(w==One) {return 1;}
        return 0;
    }
}