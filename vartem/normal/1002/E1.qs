namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Extensions.Math;
    open Microsoft.Quantum.Extensions.Convert;

    operation Solve (N : Int, Uf : ((Qubit[], Qubit) => ())) : Int[]
    {
        body
        {
            mutable result = new Int[N]; 
            using (x = Qubit[N]) {
                using (y = Qubit[1]) {
                    for (i in 0..N-1) {
                        H(x[i]);
                    }
                    X(y[0]);
                    H(y[0]);
                    Uf(x, y[0]);
                    for (i in 0..N-1) {
                        H(x[i]);
                        if (M(x[i]) == One) {
                            set result[i] = 1;
                        }
                    }
                    ResetAll(x);
                    ResetAll(y);
                }
            }
            return result;
        }
    }

    operation RunQsharp () : Int
    {
        body
        {   
            return 0;
        }
    }
}