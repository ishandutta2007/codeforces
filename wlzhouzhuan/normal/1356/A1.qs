namespace Solution {
  open Microsoft.Quantum.Intrinsic;
  
  operation Solve (unitary: (Qubit => Unit is Adj+Ctl)): Int {
    using (q = Qubit()) {
      unitary(q);
      if (M(q) == Zero) {
        Reset(q);
        return 0;
      } else {
        Reset(q);
        return 1;
      }
    }
  }
}