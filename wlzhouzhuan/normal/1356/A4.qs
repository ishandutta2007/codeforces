namespace Solution {
  open Microsoft.Quantum.Intrinsic;
  open Microsoft.Quantum.Measurement;
  
  operation Solve (unitary: (Qubit[] => Unit is Adj+Ctl)): Int {
    mutable ret = 0;
    using (q = Qubit[2]) {
      unitary(q);
      if (M(q[1]) == One) {
        set ret = 0;
      } else {
        set ret = 1;
      }
      ResetAll(q);
    }
    return ret;
  }
}