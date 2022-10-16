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
            for (i in 0..N-1) {
                set result[i] = 1;
            }
            using (x = Qubit[N]) {
                using (y = Qubit[1]) {
                    Uf(x, y[0]);
                    let res = M(y[0]);
                    if (res == One) {
                        set result[0] = 0;
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