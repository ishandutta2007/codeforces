namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Measurement;

    operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        using(qubits=Qubit[2]){
            H(qubits[0]);
            CNOT(qubits[0], qubits[1]);
            Controlled unitary([qubits[0]], qubits[1]);
    
            CNOT(qubits[1], qubits[0]);
            H(qubits[1]);
    
            if(MResetZ(qubits[1])==One){
                return 0;
            }else{
                return 1;
            }
            
        }
    }
}