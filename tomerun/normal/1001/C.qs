namespace Solution
{
	open Microsoft.Quantum.Canon;
	open Microsoft.Quantum.Primitive;

	operation Solve (qs : Qubit[]) : ()
	{
		body
		{
			H(qs[0]);
			for (i in 1..(Length(qs) - 1))
			{
				CNOT(qs[0], qs[i]);
			}
		}
	}

	operation SolveTest (count : Int) : (Int, Int)
	{
		body
		{
			mutable numOnes = 0;
			for (test in 1..count)
			{
				for (n in 1..8)
				{
					using (qubits = Qubit[n])
					{
						ResetAll(qubits);
						Solve (qubits);
						let res = M (qubits[0]);
						if (res == One)
						{
							set numOnes = numOnes + 1;
						}
						ResetAll(qubits);
					}
				}
			}
			return (count * 8 -numOnes, numOnes);
		}
	}}