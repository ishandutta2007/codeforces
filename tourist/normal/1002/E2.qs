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
		    mutable res = new Int[N];
            using (qs = Qubit[N])
            {
			    using (q = Qubit[1])
				{
				    for (i in 0..N-1) {
						Set(Zero, qs[i]);
					}
					Set(Zero, q[0]);
					Uf(qs, q[0]);
					for (i in 0..N-1) {
						set res[i] = 1;
					}
				    if (M(q[0]) == One) {
					    set res[0] = 0;
					}
					for (i in 0..N-1) {
						Set(Zero, qs[i]);
					}
					Set(Zero, q[0]);
				}
            }
			return res;
        }
    }
}