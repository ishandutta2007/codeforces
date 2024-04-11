namespace Solution {
    open Microsoft.Quantum.Arrays;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Intrinsic;

    operation Solve (qs : Qubit[]) : Unit {
        let n = Length(qs);
        X(qs[n - 1]);
        for (i in n - 2 .. -1 .. 0) {
            Controlled CX(qs[0 .. i - 1], (qs[n - 1], qs[i]));
        }
        within {
            X(qs[n - 1]);
        }
        apply {
            for (i in 0 .. n - 2) {
                Controlled CX(qs[0 .. i - 1], (qs[n - 1], qs[i]));
            }
        }
        within {
            for (i in 0 .. n - 2) {
                CX(qs[n - 1], qs[i]);
            }
        }
        apply {
            H(qs[n - 1]);
        }
    }
}