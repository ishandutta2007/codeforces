namespace Solution {
  open Microsoft.Quantum.Intrinsic;
  open Microsoft.Quantum.Convert;
  open Microsoft.Quantum.Canon;
  
  operation Solve(unitary: (Qubit[] => Unit is Adj+Ctl)): Int {
    using ((q1, q2) = (Qubit(), Qubit())) {
      X(q1);
      unitary([q1, q2]);
      let r1 = M(q2);
      ResetAll([q1, q2]);
      X(q2);
      unitary([q1, q2]);
      let r2 = M(q1);
      ResetAll([q1, q2]);
      return ResultArrayAsInt([r1, r2]);
    }
  }
}