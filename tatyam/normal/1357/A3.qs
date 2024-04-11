namespace Solution {
    open Microsoft.Quantum.Intrinsic;

    operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        mutable ans = 0;
        using (q = Qubit()) {
            unitary(q);
            Z(q);
            unitary(q);
            if (M(q) == Zero) {
                set ans = 1;
            }
            Reset(q);
        }
        return ans;
    }
}