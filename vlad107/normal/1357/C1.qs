namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Math;
    open Microsoft.Quantum.Arrays;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : Unit {
        let n = Length(qs);
        using (anc = Qubit()) {
            repeat {
                ApplyToEach(H, qs);
                Controlled X(qs, anc);
                let m = M(anc);
                Reset(anc);
            } until (m == Zero) 
            fixup {
                ResetAll(qs);
            }
        }
    }
}