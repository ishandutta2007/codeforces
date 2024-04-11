namespace Solution {
    open Microsoft.Quantum.Intrinsic;

    operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        mutable rs=One;
        using(s=Qubit()) {
            unitary(s);
            X(s);
            unitary(s);
            set rs=M(s);
            if(rs==One) {X(s);}
        }
        if(rs==One) {return 1;}
        return 0;
    }
}