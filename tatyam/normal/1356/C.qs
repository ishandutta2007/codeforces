namespace Solution {
    open Microsoft.Quantum.Intrinsic;

    operation Solve (qs : Qubit[]) : Unit {
        using (q = Qubit()){
            repeat {
                H(qs[0]);
                H(qs[1]);
                Controlled X(qs, q);
            }
            until (M(q) == Zero)
            fixup {
                ResetAll(qs);
                Reset(q);
            }
        }
        X(qs[0]);
        X(qs[1]);
    }
}