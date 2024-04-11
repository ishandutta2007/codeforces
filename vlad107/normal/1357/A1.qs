namespace Solution {
    open Microsoft.Quantum.Intrinsic;

    operation Solve (unitary : (Qubit[] => Unit is Adj+Ctl)) : Int {
        mutable result = Zero;
        using (qs = Qubit[2]) {
            X(qs[0]);
            unitary(qs);
            set result = M(qs[1]);
            ResetAll(qs);
        }
        return result == One ? 0 | 1;
    }
}