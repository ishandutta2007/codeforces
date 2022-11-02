namespace Solution {
    open Microsoft.Quantum.Intrinsic;

    operation Solve (unitary : (Qubit[] => Unit is Adj+Ctl)) : Int {
        mutable result = 0;
        using (qs = Qubit[2]) {
            X(qs[0]);
            unitary(qs);
            let r1 = M(qs[1]);
            if (r1 == One) {
                let r0 = M(qs[0]);
                if (r0 == Zero) {
                    set result = 3;
                } else {
                    set result = 1;
                }
            } else {
                ResetAll(qs);
                X(qs[1]);
                unitary(qs);
                let r0 = M(qs[0]);
                if (r0 == Zero) {
                    set result = 0;
                } else {
                    set result = 2;
                }
            }
            ResetAll(qs);
        }
        return result;
    }
}