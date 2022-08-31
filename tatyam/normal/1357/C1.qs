namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Convert;
    open Microsoft.Quantum.Math;
    open Microsoft.Quantum.Diagnostics;
    
    operation Solve (qs : Qubit[]) : Unit {
        using (q = Qubit()){
            repeat {
                ApplyToEach(H, qs);
                Controlled X(qs, q);
            }
            until (M(q) == Zero)
            fixup {
                ResetAll(qs);
                Reset(q);
            }
        }
    }
}