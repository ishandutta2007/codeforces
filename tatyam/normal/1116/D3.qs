namespace Solution {
    open Microsoft.Quantum.Arrays;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Intrinsic;

    operation Solve (qs : Qubit[]) : Unit {
        let n = Length(qs);
        within {
            for (i in 1 .. n - 1) {
                CX(qs[0], qs[i]);
            }
        }
        apply {
            H(qs[0]);
        }
    }
}