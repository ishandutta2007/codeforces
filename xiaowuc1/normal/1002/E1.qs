namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Set (desired: Result, q1: Qubit) : ()
    {
        body
        {
            let current = M(q1);
            if (desired != current)
            {
                X(q1);
            }
        }
    }

    operation Solve (N : Int, Uf : ((Qubit[], Qubit) => ())) : Int[]    
    {
        body
        {
            mutable ans = new Int[N];
            using (qubits = Qubit[N]) {
                for(i in 0..N-1) {
                    H(qubits[i]);
                }
                using (output = Qubit[1]) {
                    Set(One, output[0]);
                    H(output[0]);
                    Uf(qubits, output[0]);
                    ResetAll(output);
                }
                for(i in 0..N-1) {
                    H(qubits[i]);
                }
                for(i in 0..N-1) {
                    let res = M(qubits[i]);
                    if(res == One) {
                        set ans[i] = 1;
                    }
                }
                ResetAll(qubits);    
            }
            return ans;
        }
    }
}