namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : Unit {
        let N = Length(qs);
        for (i in 1 .. N - 1) {
            CNOT(qs[0], qs[i]);
        }
        H(qs[0]);
        for (i in 1 .. N - 1) {
            CNOT(qs[0], qs[i]);
        }
        // 01234567
        for (i in 0 .. N - 2) {
            X(qs[i]);
        }
        // 32107654
        for (i in N - 3 .. -1 .. -1) {
            Controlled X(qs[N - 1 .. N - 1] + qs[0 .. i], qs[i + 1]);
        }
        // 32104765
        for (i in 0 .. N - 1) {
            X(qs[i]);
        }
        // 45673012
        for (i in N - 3 .. -1 .. -1) {
            Controlled X(qs[N - 1 .. N - 1] + qs[0 .. i], qs[i + 1]);
        }
        // 56743012
    }
}