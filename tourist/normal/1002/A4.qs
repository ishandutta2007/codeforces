namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

	operation CCCNOT (q1 : Qubit, q2 : Qubit, q3 : Qubit, q4 : Qubit) : ()
	{
		body {
			using (tmp = Qubit[1]) {
				CCNOT(q1, q2, tmp[0]);
				CCNOT(q3, tmp[0], q4);
				CCNOT(q1, q2, tmp[0]);
			}
		}
	}

	operation CCCCNOT (q1 : Qubit, q2 : Qubit, q3 : Qubit, q4 : Qubit, q5 : Qubit) : ()
	{
		body {
			using (tmp = Qubit[2]) {
				CCNOT(q1, q2, tmp[0]);
				CCNOT(q3, tmp[0], tmp[1]);
				CCNOT(q4, tmp[1], q5);
				CCNOT(q3, tmp[0], tmp[1]);
				CCNOT(q1, q2, tmp[0]);
			}
		}
	}

    operation Solve (qs : Qubit[]) : ()
    {
        body
        {
		    if (Length(qs) == 1) {
				X(qs[0]);
			}
		    if (Length(qs) == 2) {
				H(qs[0]);
				CNOT(qs[0], qs[1]);
				X(qs[1]);
			}
		    if (Length(qs) == 4) {
			    H(qs[0]);
				H(qs[1]);
				CCNOT(qs[0], qs[1], qs[2]);
				X(qs[0]);
				X(qs[1]);
				CCNOT(qs[0], qs[1], qs[3]);
				X(qs[0]);
				X(qs[1]);
				CNOT(qs[2], qs[0]);
				CNOT(qs[2], qs[1]);
			}
			if (Length(qs) == 8) {
			    H(qs[0]);
				H(qs[1]);
				H(qs[2]);
				CCCNOT(qs[0], qs[1], qs[2], qs[3]);
				X(qs[0]);
				CCCNOT(qs[0], qs[1], qs[2], qs[4]);
				X(qs[0]);
				X(qs[1]);
				CCCNOT(qs[0], qs[1], qs[2], qs[5]);
				X(qs[1]);
				X(qs[2]);
				CCCNOT(qs[0], qs[1], qs[2], qs[6]);
				X(qs[2]);
				X(qs[0]);
				X(qs[1]);
				X(qs[2]);
				CCCNOT(qs[0], qs[1], qs[2], qs[7]);
				X(qs[0]);
				X(qs[1]);
				X(qs[2]);
				CNOT(qs[3], qs[0]);
				CNOT(qs[3], qs[1]);
				CNOT(qs[3], qs[2]);
				CNOT(qs[4], qs[1]);
				CNOT(qs[4], qs[2]);
				CNOT(qs[5], qs[0]);
				CNOT(qs[5], qs[2]);
				CNOT(qs[6], qs[0]);
				CNOT(qs[6], qs[1]);
			}
		    if (Length(qs) == 16) {
			    H(qs[0]);
				H(qs[1]);
				H(qs[2]);
				H(qs[3]);
				CCCCNOT(qs[0], qs[1], qs[2], qs[3], qs[4]);
				X(qs[0]);
				CCCCNOT(qs[0], qs[1], qs[2], qs[3], qs[5]);
				X(qs[0]);
				X(qs[1]);
				CCCCNOT(qs[0], qs[1], qs[2], qs[3], qs[6]);
				X(qs[1]);
				X(qs[2]);
				CCCCNOT(qs[0], qs[1], qs[2], qs[3], qs[7]);
				X(qs[2]);
				X(qs[3]);
				CCCCNOT(qs[0], qs[1], qs[2], qs[3], qs[8]);
				X(qs[3]);
				X(qs[0]);
				X(qs[1]);
				CCCCNOT(qs[0], qs[1], qs[2], qs[3], qs[9]);
				X(qs[0]);
				X(qs[1]);
				X(qs[0]);
				X(qs[2]);
				CCCCNOT(qs[0], qs[1], qs[2], qs[3], qs[10]);
				X(qs[0]);
				X(qs[2]);
				X(qs[0]);
				X(qs[3]);
				CCCCNOT(qs[0], qs[1], qs[2], qs[3], qs[11]);
				X(qs[0]);
				X(qs[3]);
				X(qs[1]);
				X(qs[2]);
				CCCCNOT(qs[0], qs[1], qs[2], qs[3], qs[12]);
				X(qs[1]);
				X(qs[2]);
				X(qs[1]);
				X(qs[3]);
				CCCCNOT(qs[0], qs[1], qs[2], qs[3], qs[13]);
				X(qs[1]);
				X(qs[3]);
				X(qs[2]);
				X(qs[3]);
				CCCCNOT(qs[0], qs[1], qs[2], qs[3], qs[14]);
				X(qs[2]);
				X(qs[3]);
				X(qs[0]);
				X(qs[1]);
				X(qs[2]);
				X(qs[3]);
				CCCCNOT(qs[0], qs[1], qs[2], qs[3], qs[15]);
				X(qs[0]);
				X(qs[1]);
				X(qs[2]);
				X(qs[3]);
				CNOT(qs[4], qs[0]);
				CNOT(qs[4], qs[1]);
				CNOT(qs[4], qs[2]);
				CNOT(qs[4], qs[3]);
				CNOT(qs[5], qs[1]);
				CNOT(qs[5], qs[2]);
				CNOT(qs[5], qs[3]);
				CNOT(qs[6], qs[0]);
				CNOT(qs[6], qs[2]);
				CNOT(qs[6], qs[3]);
				CNOT(qs[7], qs[0]);
				CNOT(qs[7], qs[1]);
				CNOT(qs[7], qs[3]);
				CNOT(qs[8], qs[0]);
				CNOT(qs[8], qs[1]);
				CNOT(qs[8], qs[2]);
				CNOT(qs[9], qs[2]);
				CNOT(qs[9], qs[3]);
				CNOT(qs[10], qs[1]);
				CNOT(qs[10], qs[3]);
				CNOT(qs[11], qs[1]);
				CNOT(qs[11], qs[2]);
				CNOT(qs[12], qs[0]);
				CNOT(qs[12], qs[3]);
				CNOT(qs[13], qs[0]);
				CNOT(qs[13], qs[2]);
				CNOT(qs[14], qs[0]);
				CNOT(qs[14], qs[1]);
			}
        }
    }
}