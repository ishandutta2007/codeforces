namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Measurement;

    operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
         using (qubit = Qubit()) {
             unitary(qubit);
             //mutable res = new Result;
             //set res = M(qubit);
             //unitary(qubit);
             //return (res != Zero) ? 1 : 0;
            return MResetZ(qubit) != Zero ? 1 | 0;
         }
    }
}