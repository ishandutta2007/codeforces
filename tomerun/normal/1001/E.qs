namespace Solution
{
	open Microsoft.Quantum.Canon;
	open Microsoft.Quantum.Primitive;

	operation Solve (qs : Qubit[]) : Int
	{
		body
		{
			CNOT(qs[0], qs[1]);
			H(qs[0]);
			let res0 = M(qs[0]);
			let res1 = M(qs[1]);
			if (res0 == Zero)
			{
				if (res0 == res1)
				{
					return 0;
				}
				else
				{
					return 2;
				}
			}
			else
			{
				if (res0 == res1)
				{
					return 3;
				}
				else
				{
					return 1;
				}
			}
		}
	}

	operation Setup(qs : Qubit[], index : Int) : ()
	{
        body
        {
       		ResetAll(qs);
        	H(qs[0]);
        	CNOT(qs[0], qs[1]);
        	if (index % 2 == 1) {
        		Z(qs[0]);
        	}
        	if (index / 2 == 1) {
        		X(qs[1]);
        	}
        }
	}

	operation SolveTest (count : Int) : (Int)
	{
		body
		{
			mutable accept = 0;
			using (qubits = Qubit[4])
			{
				for (test in 1..count)
				{
					for (i in 0..3)
					{
						Setup(qubits, i);
						let res = Solve(qubits);
						if (res == i)
						{
							set accept = accept + 1;
						}
					}
				}
				ResetAll(qubits);
			}
			return (accept);
		}
	}
}