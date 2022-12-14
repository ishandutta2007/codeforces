namespace Solution {
    open Microsoft.Quantum.Intrinsic;
 
    operation Solve (qubits : Qubit[]) : Unit {
        using(q=Qubit()){
            repeat{
                Reset(qubits[0]); Reset(qubits[1]); Reset(q);
                H(qubits[0]); H(qubits[1]);
                Controlled X(qubits, q);
                CNOT(qubits[0], q);
                CNOT(qubits[1], q);
            }until(M(q)==One);
            Reset(q);
        }
    }
}