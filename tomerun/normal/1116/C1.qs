namespace Solution
{
	open Microsoft.Quantum.Canon;
	open Microsoft.Quantum.Primitive;
	open Microsoft.Quantum.Extensions.Convert;
	open Microsoft.Quantum.Extensions.Diagnostics;
	open Microsoft.Quantum.Extensions.Math;

	operation Solve (x : Qubit[], y : Qubit) : () {
		body {
			let N = Length(x);
			using (anc = Qubit[N]) {
				X(anc[0]);
				for (i in 0..N-2) {
					CNOT(x[i], x[i+1]);
					CCNOT(x[i+1], anc[i], anc[i+1]);
					CNOT(x[i], x[i+1]);
				}
				CNOT(anc[N-1], y);
				for (i in N-2..-1..0) {
					CNOT(x[i], x[i+1]);
					CCNOT(x[i+1], anc[i], anc[i+1]);
					CNOT(x[i], x[i+1]);
				}
				X(anc[0]);
			}
		}
		adjoint auto;
	}

	operation SolveTest () : () {
		body {
			using (qubits = Qubit[7]) {
				H(qubits[0]);
				H(qubits[1]);
				H(qubits[2]);
				H(qubits[3]);
				H(qubits[4]);
				H(qubits[5]);
				H(qubits[6]);
				// X(qubits[0]);
				// X(qubits[2]);
				// X(qubits[4]);
				// X(qubits[6]);
				using (y = Qubit[1]) {
					Solve(qubits, y[0]);
					DumpMachine(ToStringIFormat(0, "dump-0.\\.txt"));
					ResetAll(y);
				}
				ResetAll(qubits);
			}
		}
	}
}