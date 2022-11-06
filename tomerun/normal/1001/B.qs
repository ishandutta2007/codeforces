namespace Solution
{
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Primitive;

    operation Solve (qs : Qubit[], index : Int) : ()
    {
        body
        {
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

    operation SolveTest (count : Int) : (Int, Int)
    {
        body
        {
            mutable numOnes = 0;
            using (qubits = Qubit[2])
            {
            	for (test in 1..count)
            	{
            		for (index in 0..3)
            		{
		                ResetAll(qubits);
		                Solve (qubits, index);
		                let res = M (qubits[0]);
		                if (res == One)
		                {
		                    set numOnes = numOnes + 1;
		                }
            		}
            	}
                Reset(qubits[0]);
            }
            return (count * 4 -numOnes, numOnes);
        }
    }}