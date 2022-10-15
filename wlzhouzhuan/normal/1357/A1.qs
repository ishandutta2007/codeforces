namespace Solution {
  open Microsoft.Quantum.Intrinsic;
  open Microsoft.Quantum.Convert;
  open Microsoft.Quantum.Canon;
  
  operation Solve(unitary: (Qubit[] => Unit is Adj+Ctl)): Int {
    using ((q1, q2) = (Qubit(), Qubit())) {
      X(q2);
      unitary([q1, q2]);
      let res = ResultAsBool(M(q1));
      ResetAll([q1, q2]);
      return res ? 1 | 0;
    }
  }
}