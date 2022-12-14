namespace Solution {
    open Microsoft.Quantum.Measurement;
    operation Solve (unitary : (Qubit[] => Unit is Adj+Ctl)) : Int {
        using(qubits=Qubit[2]){
            unitary(qubits);
            if(MResetZ(qubits[1])==One){
                return 0;
            }else{
                return 1;
            }
        }
    }
}