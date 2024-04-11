namespace Solution
{
	open Microsoft.Quantum.Canon;
	open Microsoft.Quantum.Primitive;

	operation Solve (N : Int, Uf : ((Qubit[], Qubit) => ())) : Bool
	{
		body
		{
			mutable res = true;
			using (qs = Qubit[N])
			{
				using (reg = Qubit[1])
				{
					X(reg[0]);
					for (i in 0..(N-1))
					{
						H(qs[i]);
					}
					H(reg[0]);
					Uf(qs, reg[0]);
					for (i in 0..(N-1))
					{
						H(qs[i]);
					}
					for (i in 0..(N-1))
					{
						if (M(qs[i]) == One)
						{
							set res = false;
						}
					}
					ResetAll(qs);
					ResetAll(reg);
				}
			}
			return res;
		}
	}
}