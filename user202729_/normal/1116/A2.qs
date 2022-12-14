namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qubits : Qubit[], bits : Bool[][]) : Unit {
        using(tmp=Qubit[2]){
            repeat{
                H(tmp[0]); H(tmp[1]);
                for(i in 0..Length(qubits)-1){
                    X(tmp[0]);
                    if(bits[0][i]){ Controlled X(tmp, qubits[i]); }
                    X(tmp[1]);
                    if(bits[1][i]){ Controlled X(tmp, qubits[i]); }
                    X(tmp[0]);
                    if(bits[2][i]){ Controlled X(tmp, qubits[i]); }
                    X(tmp[1]);
                    if(bits[3][i]){ Controlled X(tmp, qubits[i]); }
                }

                H(tmp[0]); H(tmp[1]);
                
            }until(M(tmp[0])==Zero and M(tmp[1])==Zero)
            fixup{
                
                ResetAll(tmp); ResetAll(qubits);
            }
        }
    }
}