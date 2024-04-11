namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Math;
    open Microsoft.Quantum.Arrays;
    open Microsoft.Quantum.Canon;

    operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        using (qs = Qubit[2]) {
            H(qs[0]);
            Controlled unitary(qs[0..0], qs[1]);
            Controlled unitary(qs[0..0], qs[1]);
            H(qs[0]);
            let m0 = M(qs[0]);
            ResetAll(qs);

            mutable result = 0;
            if (m0 == Zero) {
                H(qs[0]);
                Controlled unitary(qs[0..0], qs[1]);
                Controlled Y(qs[0..0], qs[1]);
                H(qs[0]);
                let m1 = M(qs[0]);
                if (m1 == Zero) {
                    set result = 0;
                } else {
                    set result = 2;
                }
            } else {
                H(qs[0]);
                Controlled unitary(qs[0..0], qs[1]);
                CNOT(qs[0], qs[1]);
                H(qs[0]);
                let m1 = M(qs[0]);
                if (m1 == Zero) {
                    set result = 3;
                } else {
                    set result = 1;
                }
            }
            ResetAll(qs);
            return result;
        }
    }
}