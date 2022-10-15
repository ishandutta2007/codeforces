namespace Solution {
  open Microsoft.Quantum.Intrinsic;
  open Microsoft.Quantum.Convert;
  open Microsoft.Quantum.Canon;
  
  operation Solve(unitary: (Qubit => Unit is Adj+Ctl)): Int {
    using (q = Qubit()) {
      H(q);
      unitary(q);
      H(q);
      unitary(q);
      let res = M(q);
      Reset(q);
      return res == One ? 1 | 0;
    }
  }
}