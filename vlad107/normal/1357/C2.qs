namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Math;

    operation Solve (qs : Qubit[], parity : Int) : Unit {
        let n = Length(qs);
        for (i in 0..n - 2) {
            H(qs[i]);
        }
        if (parity == 1) {
            X(qs[n - 1]);
        }
        for (i in 0..n - 2) {
            CNOT(qs[i], qs[n - 1]);
        }
    }
}