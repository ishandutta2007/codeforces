namespace Solution {
    open Microsoft.Quantum.Intrinsic;

    operation Solve (qubits : Qubit[]) : Unit {
        using(ancillary=Qubit()){
            repeat{
                for(i in 0..Length(qubits)-1){
                    H(qubits[i]);
                }
                Controlled X(qubits, ancillary);
            }until(M(ancillary)==Zero)
            fixup{
                ResetAll(qubits);
                Reset(ancillary);
            }
        }
    }
}