namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Measurement;

    operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
         using (qubit = Qubit()) {
            H(qubit);
            unitary(qubit);
            unitary(qubit);
            H(qubit);
            return MResetZ(qubit) != Zero ? 1 | 0;
         }
    }
}