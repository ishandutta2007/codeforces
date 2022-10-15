namespace Solution {
  open Microsoft.Quantum.Intrinsic;
  open Microsoft.Quantum.Convert;
  open Microsoft.Quantum.Canon;
  open Microsoft.Quantum.Math;
  
  operation Solve(unitary: ((Double, Qubit) => Unit is Adj+Ctl)): Int {
    using ((q1, q2) = (Qubit(), Qubit())) {
      H(q1);
      Controlled unitary([q1], (2.0 * PI(), q2));
      H(q1);
      let res = M(q1);
      Reset(q1);
      return res == One ? 0 | 1;
    }
  }
}