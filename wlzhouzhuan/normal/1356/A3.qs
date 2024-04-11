namespace Solution {
  open Microsoft.Quantum.Intrinsic;
  open Microsoft.Quantum.Measurement;
  
  operation Solve (unitary: (Qubit => Unit is Adj+Ctl)): Int {
    using (q = Qubit()) {
      H(q);
      unitary(q);
      unitary(q);
      H(q);
      return MResetZ(q) == Zero ? 0 | 1;
    }
  }
}