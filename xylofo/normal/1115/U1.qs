namespace Solution {
  open Microsoft.Quantum.Primitive;
  open Microsoft.Quantum.Canon;

  operation Solve (x: Qubit[], y: Qubit) : Unit {
    body (...) {
      let N = Length(x);
      using(anchillas = Qubit[N-1]) {
        for(i in 0 .. N-2) {
          CNOT (x[i], anchillas[i]);
          CNOT (x[i+1], anchillas[i]);
        }

        Controlled X (anchillas, y);

        for(i in 0 .. N-2) {
          CNOT (x[i+1], anchillas[i]);
          CNOT (x[i], anchillas[i]);
        }
      }
    }
    adjoint auto;
  }
}