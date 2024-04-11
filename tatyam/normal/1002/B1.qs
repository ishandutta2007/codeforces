namespace Solution {
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Intrinsic;

    operation Solve (qs : Qubit[]) : Int {
        let N = Length(qs);
        for (i in 0 .. N - 2) {
            CX(qs[i], qs[i + 1]);
        }
        if (M(qs[N - 1]) == One) {
            return 1;
        }
        return 0;
    }
}