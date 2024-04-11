namespace Solution {
  open Microsoft.Quantum.Primitive;
  open Microsoft.Quantum.Canon;

  operation Solve (x: Qubit[], y: Qubit) : Unit {
    body (...) {
      let N = Length(x);
      using (mod = Qubit[3]) {
        X (mod[0]);
        for (i in 0 .. N-1) {
          Controlled SWAP ([x[i]], (mod[0], mod[1]));
          Controlled SWAP ([x[i]], (mod[0], mod[2]));
        }

        CNOT(mod[0], y);

        // untangle
        for (i in 0 .. N-1) {
          using (temp = Qubit()) {
            Controlled SWAP ([x[i]], (mod[0], mod[2]));
            Controlled SWAP ([x[i]], (mod[0], mod[1]));
          }
        }
        X (mod[0]);
      }
    }
    adjoint auto;
  }
}