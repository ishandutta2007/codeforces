namespace Solution {
  open Microsoft.Quantum.Primitive;
  open Microsoft.Quantum.Canon;

  operation W4(x: Qubit[]) : Unit {
    using (tmp = Qubit()) {
      X(x[0]);

      H(tmp);
      Controlled SWAP ([tmp], (x[0], x[1]));
      CNOT(x[1], tmp);

      H(tmp);
      Controlled SWAP ([tmp], (x[0], x[2]));
      Controlled SWAP ([tmp], (x[1], x[3]));
      CNOT(x[2], tmp);
      CNOT(x[3], tmp);
    }
  }

  operation Solve (qs: Qubit[]) : Unit {
    using (tmp = Qubit[2]) {
      repeat {
        W4([qs[0], qs[1], tmp[0], tmp[1]]);
      } until (M(tmp[1]) == Zero)
      fixup {
          ResetAll(qs);
          ResetAll(tmp);
      }
      (ControlledOnInt(0,X))(qs, tmp[0]);
    }
  }
}