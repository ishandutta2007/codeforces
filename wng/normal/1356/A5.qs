namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Measurement;

    operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
         using (qs = Qubit[2]) {
            H(qs[0]);
            Controlled unitary(qs[0..0],qs[1]);
            return MResetX(qs[0]) != Zero ? 1 | 0;
         }
    }
}