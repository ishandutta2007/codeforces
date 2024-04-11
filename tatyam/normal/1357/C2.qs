namespace Solution {

    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Convert;
    open Microsoft.Quantum.Math;
    open Microsoft.Quantum.Diagnostics;
    
    operation Solve (qs : Qubit[], parity : Int) : Unit {
        using (q0 = Qubit()){
            repeat {
                for (q in qs) {
                    H(q);
                    CNOT(q, q0);
                }
            }
            until (BoolArrayAsInt([ResultAsBool(M(q0))]) == parity)
            fixup {
                ResetAll(qs);
                Reset(q0);
            }
            Reset(q0);
        }
    }
}