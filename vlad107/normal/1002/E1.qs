namespace Solution
{
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Extensions.Bitwise;

    operation Solve (N : Int, Uf : ((Qubit[], Qubit) => ())) : Int[]
    {
        body
        {
            mutable result = new Int[N];
            using (qs = Qubit[N])
            {
                for (i in 0..N - 1)
                {
                    H(qs[i]);
                }
                using (y = Qubit[1])
                {
                    X(y[0]);
                    H(y[0]);
                    Uf(qs, y[0]);
                    for (i in 0..N - 1)
                    {
                        H(qs[i]);
                    }
                    for (i in 0..N - 1)
                    {
                        if (M(qs[i]) == One)
                        {
                            set result[i] = 1;
                        } else
                        {
                            set result[i] = 0;
                        }
                    }
                    ResetAll(y);
                }
                ResetAll(qs);
            }
            return result;
        }
    }
}