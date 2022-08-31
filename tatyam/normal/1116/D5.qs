namespace Solution {
    open Microsoft.Quantum.Arrays;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Intrinsic;

    operation Solve (qs : Qubit[]) : Unit {
        within {
            CCNOT(qs[2], qs[0], qs[1]);
        }
        apply {
            CCNOT(qs[0], qs[1], qs[2]);
        }
        H(qs[0]);
        within {
            CX(qs[2], qs[1]);
        }
        apply {
            CX(qs[1], qs[2]);
        }
        within {
            X(qs[1]);
            CX(qs[1], qs[2]);
        }
        apply {
            Controlled H(qs[2 .. 2], qs[1]);
        }
    }
}