namespace Solution {
  open Microsoft.Quantum.Intrinsic;
  open Microsoft.Quantum.Measurement;
  open Microsoft.Quantum.Math;

  operation Solve (unitary: (Qubit => Unit is Adj+Ctl)): Int {
    mutable ret = 0;
    using (q = Qubit[2]) {
      H(q[0]);
      Controlled unitary([q[0]], q[1]);
      H(q[0]);
      if (M(q[0]) == One) {
        set ret = 1;
      } else {
        set ret = 0;
      }
      ResetAll(q);
    }
    return ret;
  }
}