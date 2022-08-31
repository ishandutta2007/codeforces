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
	
    operation Solve (qs : Qubit[]) : Int
    {
        body
        {
			Z(qs[0]); X(qs[0]); Z(qs[0]); X(qs[0]);
                        Z(qs[1]); X(qs[1]); Z(qs[1]); X(qs[1]);
                        H(qs[0]);
			CNOT(qs[0], qs[1]);
			H(qs[0]);
			mutable res = 0;
			if (M(qs[0]) == One) {
				set res = res + 1;
			}
			if (M(qs[1]) == One) {
				set res = res + 2;
			}
                        if (res == 0 || res == 3) {
                                set res = 3 - res;
                        }
			return res;
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
					let tmp = Solve(qubits);

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