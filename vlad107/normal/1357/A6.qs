namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Math;
    open Microsoft.Quantum.Arrays;
    open Microsoft.Quantum.Canon;

    operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        using (q = Qubit[2]) {
            H(q[0]);
            CNOT(q[0], q[1]);
            unitary(q[0]);
            CNOT(q[0], q[1]);
            H(q[0]);
            let m0 = (M(q[0]) == Zero) ? 0 | 1;
            let m1 = (M(q[1]) == Zero) ? 0 | 1;
            ResetAll(q);
            mutable result = 0;
            if (m0 == 0) {
                set result = m1;
            } else {
                set result = 3 - m1;
            }
            return result;
        }
    }
}