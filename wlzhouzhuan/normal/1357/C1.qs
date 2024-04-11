namespace Solution {
  open Microsoft.Quantum.Canon;
  open Microsoft.Quantum.Arithmetic;
  open Microsoft.Quantum.Intrinsic;
  
  operation Solve(qs: Qubit[]): Unit {
    using (q = Qubit()) {
      repeat {
        ApplyToEach(H, qs);
        Controlled X(qs, (q));
      } until(M(q) == Zero)
      fixup {
        ApplyToEach(X, qs);
        X(q);
      }
    }
  }
}