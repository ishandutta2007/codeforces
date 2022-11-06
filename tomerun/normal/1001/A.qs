namespace Solution
{
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Primitive;

    operation Solve (q : Qubit, sign : Int) : ()
    {
        body
        {
        	H(q);
        	if (sign == -1) {
        		Z(q);
        	}
        }
    }

    operation SolveTest (count : Int) : (Int, Int)
    {
        body
        {
            mutable numOnes = 0;
            using (qubits = Qubit[1])
            {
            	for (test in 1..count)
            	{
            		for (sign in -1..2..1)
            		{
		                Reset(qubits[0]);
		                Solve (qubits[0], sign);
		                let res = M (qubits[0]);
		                if (res == One)
		                {
		                    set numOnes = numOnes + 1;
		                }
            		}
            	}
                Reset(qubits[0]);
            }
            return (count * 2 -numOnes, numOnes);
        }
    }}