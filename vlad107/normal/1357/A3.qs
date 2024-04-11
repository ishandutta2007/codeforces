namespace Solution {
    open Microsoft.Quantum.Intrinsic;

    operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        mutable result = 0;
        using (q = Qubit()) {
            unitary(q);
            Z(q);
            unitary(q);
            let r = M(q);
            set result = r == Zero ? 1 | 0;
            Reset(q);
        }
        return result;
    }
}