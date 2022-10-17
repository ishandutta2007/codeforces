namespace Solution {
  open Microsoft.Quantum.Primitive;
  open Microsoft.Quantum.Canon;

  operation Solve (x: Qubit[], y: Qubit) : Unit {
    body (...) {
      let N = Length(x);
      let A = N / 2;
      using(anchillas = Qubit[N]) {
        for(p in A .. N-1) {
          for(i in 0 .. N-1-p) {
            CNOT (x[i], anchillas[i]);
            CNOT (x[i+p], anchillas[i]);
          }

          (ControlledOnInt(0, X))(anchillas[0 .. N-1-p], anchillas[N-p]);

          for(i in 0 .. N-1-p) {
            CNOT (x[i], anchillas[i]);
            CNOT (x[i+p], anchillas[i]);
          }
        }

        //DumpMachine($"bla.txt");
        (ControlledOnInt(0, X))(anchillas[1 .. N-1], y);
        X (y);

        for(pp in 1 .. N-A) {
          let p = N-pp;
          for(i in 0 .. N-1-p) {
            CNOT (x[i], anchillas[i]);
            CNOT (x[i+p], anchillas[i]);
          }

          (ControlledOnInt(0, X))(anchillas[0 .. N-1-p], anchillas[N-p]);

          for(i in 0 .. N-1-p) {
            CNOT (x[i], anchillas[i]);
            CNOT (x[i+p], anchillas[i]);
          }
        }
      }
    }
    adjoint auto;
  }
}