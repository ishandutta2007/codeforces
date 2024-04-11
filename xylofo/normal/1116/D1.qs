namespace Solution {
  open Microsoft.Quantum.Primitive;
  open Microsoft.Quantum.Canon;

  operation Solve (qs: Qubit[]) : Unit {
    body (...) {
      let N = Length(qs);
      H(qs[0]);
    }
    adjoint auto;
  }
}