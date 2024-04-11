namespace Solution {
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Intrinsic;

    operation Flip (qs : Qubit[]) : Unit is Ctl {
        let N = Length(qs);
        if (N == 1) {
            return ();
        }
        let N2 = N / 2;
        H(qs[0]);
        for (i in 1 .. N - 1) {
            CX(qs[0], qs[i]);
        }
        ApplyToEachC(X, qs[N2 ...]);
        Controlled Flip(qs[... N2 - 1], qs[N2 ...]);
        Controlled Flip(qs[N2 ...], qs[... N2 - 1]);
    }
    
    operation Solve (qs : Qubit[]) : Unit {
        Flip(qs);
        ApplyToEach(X, qs);
    }
}