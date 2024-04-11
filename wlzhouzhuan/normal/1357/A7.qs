namespace Solution {
  open Microsoft.Quantum.Math;
  open Microsoft.Quantum.Measurement;
  open Microsoft.Quantum.Canon;
  open Microsoft.Quantum.Intrinsic;
  open Microsoft.Quantum.Convert;
  open Microsoft.Quantum.Arrays;
  open Microsoft.Quantum.Arithmetic;
  open Microsoft.Quantum.Preparation;
  open Microsoft.Quantum.Diagnostics;
  
  operation Solve(unitary: (Qubit => Unit is Adj+Ctl)): Int {
    using ((q1, q2) = (Qubit(), Qubit())) {
      within {
        H(q2);
        S(q2);
        H(q1);
      } apply {
        Controlled unitary([q1], q2);
        Controlled unitary([q1], q2);
      }
      let r1 = M(q1);
      ResetAll([q1, q2]);
      //  
      within {
        H(q2);
        S(q2);
        H(q1);
      } apply {
        Controlled unitary([q1], q2);
        if (r1 == One) {
          Controlled Z([q1], q2);
          Controlled X([q1], q2);
        }
      }
      let r2 = M(q1);
      ResetAll([q1, q2]);
      return ResultArrayAsInt([r1, r2]);
    }
  }
}