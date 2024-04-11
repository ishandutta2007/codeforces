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
  
  operation Solve(theta: Double, unitary: (Qubit => Unit is Adj+Ctl)): Int {
    mutable ret = 0;
    let N = Round(PI() / theta);
    using (q = Qubit()) {
      mutable i = 0;
      repeat {
        for (j in 0 .. N - 1) {
          (unitary)(q);
        }
        if (MResetZ(q) == One) {
          // Message($"i = {i}");
          set ret = 1;
        } 
        set i = i + 1;
      } until(i == 10 or ret == 1);
      return ret;
    }
  }
}