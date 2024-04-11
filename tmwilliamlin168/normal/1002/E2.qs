namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (N : Int, Uf : ((Qubit[], Qubit) => ())) : Int[]
    {
        body
        {
            mutable res = new Int[N];
            using(qs = Qubit[N + 1]) {
                Uf(qs[0..(N-1)], qs[N]);
                if((M(qs[N])==One)!=(N%2==1))
                {
                    set res[0]=1;
                }
                ResetAll(qs);
            }
            return res;
        }
    }
}