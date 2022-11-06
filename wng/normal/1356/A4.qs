namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Measurement;

    operation Solve (unitary : (Qubit[] => Unit is Adj+Ctl)) : Int {
         using (qs = Qubit[2]) {
            unitary(qs);
            return MResetZ(qs[1]) == Zero ? 1 | 0;
         }
    }
}