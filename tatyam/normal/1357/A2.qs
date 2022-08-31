namespace Solution {
    open Microsoft.Quantum.Intrinsic;

    operation Solve (unitary : (Qubit[] => Unit is Adj+Ctl)) : Int {
        mutable ans = 0;
        using (q = Qubit[2]) {
            X(q[1]);
            unitary(q);
            let res0 = M(q[0]);
            let res1 = M(q[1]);
            if (res0 == One) {
                if (res1 == One) {
                    set ans = 2;
                }
                else {
                    set ans = 3;
                }
            }
            else {
                SWAP(q[0], q[1]);
                unitary(q);
                if (M(q[1]) == One) {
                    set ans = 1;
                }
            }
            ResetAll(q);
        }
        return ans;
    }
}