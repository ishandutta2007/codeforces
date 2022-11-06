namespace Solution
{
	open Microsoft.Quantum.Canon;
	open Microsoft.Quantum.Primitive;
	open Microsoft.Quantum.Extensions.Convert;
	open Microsoft.Quantum.Extensions.Diagnostics;
	open Microsoft.Quantum.Extensions.Math;

	operation Solve (x : Qubit[], y : Qubit, b : Int[]) : () {
		body {
			for (i in 0..Length(x)-1) {
				if (b[i] == 1) {
					CNOT(x[i], y);
				}
			}
		}
	}

	operation SolveTest () : () {
		body {
			for (i in 1..8) {
				using (qubits = Qubit[i]) {
					using (y = Qubit[1]) {
						X(qubits[0]);
						mutable b = new Int[i];
						set b[0] = 1;
						Solve(qubits, y[0], b);
						DumpMachine(ToStringIFormat(i, "dump-0.\\.txt"));
						Reset(y[0]);
					}
					ResetAll(qubits);
				}
			}
		}
	}
}