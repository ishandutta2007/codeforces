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
                using (output = Qubit[1]) {
                    Uf(qubits, output[0]);
                    if(N%2 == 0) {
                        if(M(output[0]) == One) {
                            set ans[0] = 1 - ans[0];
                        }
                    }
                    else {
                        if(M(output[0]) == Zero) {
                            set ans[0] = 1 - ans[0];
                        }
                    }
                    ResetAll(output);
                }
                ResetAll(qubits);    
            }
            return ans;
        }
    }

    operation SecretOracle (x : Qubit[], y : Qubit) : ()
    {
        body
        {
            for(i in 0..Length(x)-1) {
                CNOT(x[i], y);
            }
            // X(y);
        }
    }

    operation Test() : ()
    {
        body
        {
            for (k in 0..10) {
                let res = Solve(3, SecretOracle);
                Message($"{res}");
            }
        }
    }
}