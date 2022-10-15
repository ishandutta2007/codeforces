namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (N : Int, Uf : ((Qubit[], Qubit) => ())) : Int[]
    {
        body
        {
            mutable res = new Int[N];
            using(qubits = Qubit[N + 1]) {
                X(qubits[N]);
                ApplyToEach(H, qubits);
                Uf(qubits[0..(N-1)], qubits[N]);
                ApplyToEach(H, qubits[0..(N - 1)]);
                for(i in 0..(N-1))
                {
                    if(MResetZ(qubits[i])==One)
                    {
                        set res[i]=1;
                    }
                }
                Reset(qubits[N]);
            }
            return res;
        }
    }
}