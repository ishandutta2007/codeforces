namespace Solution {
    open Microsoft.Quantum.Arrays;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Intrinsic;

    operation Solve (qs : Qubit[], index : Int) : Unit {
        if ((index &&& 1) == 1) {
            X(qs[0]);
        }
        H(qs[0]);
        CX(qs[0], qs[1]);
        if ((index &&& 2) == 2) {
            X(qs[1]);
        }
    }
}