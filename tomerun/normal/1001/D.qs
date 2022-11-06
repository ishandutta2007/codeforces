namespace Solution
{
	open Microsoft.Quantum.Canon;
	open Microsoft.Quantum.Primitive;

	operation Solve (q : Qubit) : Int
	{
		body
		{
			H(q);
			let res = M(q);
			if (res == Zero)
			{
				return 1;
			} else
			{
				return -1;
			}
		}
	}

	operation SolveTest (count : Int) : (Int)
	{
		body
		{
			mutable accept = 0;
			using (qubits = Qubit[1])
			{
				for (test in 1..count)
				{
					for (i in -1..2..1)
					{
						ResetAll(qubits);
						H(qubits[0]);
						if (i == -1)
						{
							Z(qubits[0]);
						}
						let res = Solve (qubits[0]);
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
	}}