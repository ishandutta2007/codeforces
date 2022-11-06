namespace Solution
{
	open Microsoft.Quantum.Canon;
	open Microsoft.Quantum.Primitive;

	operation Solve (qs : Qubit[], bits0 : Bool[], bits1 : Bool[]) : Int
	{
		body
		{
			for (i in 0..(Length(qs) - 1))
			{
				if (bits0[i] != bits1[i])
				{
					let res = M(qs[i]);
					if ((res == One) == bits0[i])
					{
						return 0;
					}
					else
					{
						return 1;
					}
				}
			}
			return 0;
		}
	}
}