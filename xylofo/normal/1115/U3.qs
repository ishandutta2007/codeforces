namespace Solution {
  open Microsoft.Quantum.Primitive;
  open Microsoft.Quantum.Canon;

  operation Solve (qs: Qubit[]) : Unit {
    body (...) {
      let N = Length(qs);
      for(k in 2 .. N) {
        for(i in 0 .. N-k) {
          (ControlledOnInt(1,H)) (qs[N-k+1 .. N-1], qs[i]);
        }
      }
    }
    adjoint auto;
  }
}