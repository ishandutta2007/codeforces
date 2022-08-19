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

    operation Solve (N : Int, Uf : ((Qubit[], Qubit) => ())) : Bool
    {
        body
        {
		    mutable res = true;
            using (qs = Qubit[N])
            {
			    using (q = Qubit[1])
				{
				    for (i in 0..N-1) {
						Set(Zero, qs[i]);
						H(qs[i]);
					}
					Set(One, q[0]);
					H(q[0]);
					Uf(qs, q[0]);
					for (i in 0..N-1) {
						H(qs[i]);
					}
					for (i in 0..N-1) {
					    if (M(qs[i]) != Zero) {
							set res = false;
						}
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