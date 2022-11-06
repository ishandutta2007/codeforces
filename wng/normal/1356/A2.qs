namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Measurement;
    open Microsoft.Quantum.Math;

    operation Solve2 (unitary : ((Double, Qubit) => Unit is Adj+Ctl)) : Int {
         using (qubit = Qubit()) {
            H(qubit);
            unitary(TimesD(2.0, PI()),qubit);
            H(qubit);
            return MResetZ(qubit) == Zero ? 1 | 0;
         }
    }
    operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
         using (qubit = Qubit()) {
            H(qubit);
            unitary(qubit);
            H(qubit);
            return MResetZ(qubit) != Zero ? 1 | 0;
         }
    }
}