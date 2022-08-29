namespace Solution {
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Intrinsic;
    
    operation Solve (qs : Qubit[], bits0 : Bool[], bits1 : Bool[]) : Unit {
        let N = Length(qs);
        using (q = Qubit()) {
            H(q);
            for (i in 0 .. N - 1) {
                if (bits0[i] != bits1[i]) {
                    CX(q, qs[i]);
                }
                else {
                    X(qs[i]);
                }
            }
            Controlled X(qs, q);
        }
        for (i in 0 .. N - 1) {
            if (not bits1[i]) {
                X(qs[i]);
            }
        }
    }
}