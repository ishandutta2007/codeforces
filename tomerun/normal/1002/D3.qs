namespace Solution
{
	open Microsoft.Quantum.Canon;
	open Microsoft.Quantum.Primitive;
	open Microsoft.Quantum.Extensions.Convert;
	open Microsoft.Quantum.Extensions.Diagnostics;
	open Microsoft.Quantum.Extensions.Math;

	operation Solve (x : Qubit[], y : Qubit) : () {
		body {
			CCNOT(x[0], x[1], y);
			CCNOT(x[1], x[2], y);
			CCNOT(x[2], x[0], y);
		}
	}

	operation SolveTest () : () {
		body {
			using (qubits = Qubit[3]) {
				using (y = Qubit[1]) {
					X(qubits[0]);
					// X(qubits[1]);
					// X(qubits[2]);
					Solve(qubits, y[0]);
					DumpMachine(ToStringIFormat(0, "dump-0.\\.txt"));
					Reset(y[0]);
				}
				ResetAll(qubits);
			}
		}
	}
}