namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (x : Qubit[]) : Unit {
        CNOT(x[2], x[0]);
        CNOT(x[2], x[1]);
        X(x[0]);
        X(x[1]);
        Controlled H([x[1]], x[0]);
        CNOT(x[0], x[1]);
        X(x[1]);
        SWAP(x[0], x[2]);
        H(x[0]);
    }
}