namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : Unit {
        let N = Length(qs);
        for (i in 1 .. N - 1) {
            X(qs[i]);
            ApplyToEach((ControlledOnInt(0, H))(qs[i .. N - 1], _), qs[0 .. i - 1]);
            X(qs[i]);
        }
    }
}