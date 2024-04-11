namespace Solution
{
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
	
    operation Solve (q : Qubit) : Int
    {
        body
        {
			R(PauliY, 2.0 * 0.39269908169872415480783042290994, q);
			if (M(q) == Zero) {
				return 0;
			}
			return 1;
        }
    }

	operation Test (count : Int, initial: Result) : (Int,Int,Int)
    {
        body
        {
            mutable numOnes = 0;
			mutable agree = 0;
            using (qubits = Qubit[2])
            {
                for (test in 1..count)
                {
                    Set (Zero, qubits[0]);
					Set (Zero, qubits[1]);
					let tmp = Solve(qubits[0]);

                    let res = M (qubits[0]);

                    if (M (qubits[1]) == res) 
                    {
                        set agree = agree + 1;
                    }

                    // Count the number of ones we saw:
                    if (res == One)
                    {
                        set numOnes = numOnes + 1;
                    }
                }
                Set(Zero, qubits[0]);
                Set(Zero, qubits[1]);
            }
            // Return number of times we saw a |0> and number of times we saw a |1>
            return (count-numOnes, numOnes, agree);
        }
    }
}