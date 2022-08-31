namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Convert;

    operation Solve (unitary : (Qubit[] => Unit is Adj+Ctl)) : Int {
        mutable w=One;
        using(s=Qubit[2]) {
            unitary(s);
            set w=M(s[1]);
            if(w==One) {X(s[1]);}
        }
        if(w==One) {return 0;}
        return 1;
    }
}