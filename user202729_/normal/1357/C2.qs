namespace Solution {
    open Microsoft.Quantum.Intrinsic;

    operation Solve (qubits : Qubit[], parity : Int) : Unit {
        for(i in 1..Length(qubits)-1){
            H(qubits[i]);
        }
        for(i in 1..Length(qubits)-1){
            CNOT(qubits[i], qubits[0]);
        }
        if(parity==1){
            X(qubits[0]);
        }
    }
}