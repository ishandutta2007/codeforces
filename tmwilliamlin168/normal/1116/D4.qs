namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (x : Qubit[]) : Unit {
        let n=Length(x);
        for(i in 0..n-2) {
            CNOT(x[n-1], x[i]);
            X(x[i]);
            Controlled X(x[0..i-1], x[i]);
        }
        // for(i in 0..n-2) {
            // CNOT(x[n-1], x[i]);
        // }
        H(x[n-1]);
        X(x[n-1]);
        for(i in 0..n-2) {
            CNOT(x[n-1], x[i]);
        }
    }
}