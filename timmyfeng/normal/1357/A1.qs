namespace Solution {
    open Microsoft.Quantum.Intrinsic;

    operation Solve (unitary : (Qubit[] => Unit is Adj+Ctl)) : Int {
        mutable res = Zero;
        using (qs = Qubit[2]) {
            X(qs[0]);
            unitary(qs);
            set res = M(qs[1]);
            ResetAll(qs);
        }
        return res == Zero ? 1 | 0;
    }
}