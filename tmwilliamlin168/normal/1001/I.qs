namespace Solution
{
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (N : Int, Uf : ((Qubit[], Qubit) => ())) : Bool
    {
        body
        {
            mutable res = true;
			using(q1 = Qubit[1])
			{
				X(q1[0]);
				H(q1[0]);
				using(qs = Qubit[N])
				{
					for(i in 1..N)
					{
						H(qs[i-1]);
					}
					Uf(qs, q1[0]);
					for(i in 1..N)
					{
						H(qs[i-1]);
					}
					for(i in 1..N)
					{
						if(M(qs[i-1]) == One )
						{
							set res = false;
                            X(qs[i-1]);
						}
					}
				}
				if(M(q1[0])==One)
				{
				    X(q1[0]);
				}
			}
			return res;
        }
    }
}