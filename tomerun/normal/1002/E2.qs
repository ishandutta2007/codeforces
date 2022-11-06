namespace Solution
{
	open Microsoft.Quantum.Canon;
	open Microsoft.Quantum.Primitive;
	open Microsoft.Quantum.Extensions.Convert;
	open Microsoft.Quantum.Extensions.Diagnostics;
	open Microsoft.Quantum.Extensions.Math;

	operation Solve (N : Int, Uf : ((Qubit[], Qubit) => ())) : Int[] {
		body {
			mutable res = new Int[N];
			for (i in 0..N-1) {
				set res[i] = 1;
			}
			using (x = Qubit[N]) {
				using (y = Qubit[1]) {
					Uf(x, y[0]);
					let r = M(y[0]);
					if (r == One) {
						set res[0] = 0;
					}
					Reset(y[0]);
				}
				ResetAll(x);
			}
			return res;
		}
	}

	operation SolveTest () : () {
		body {
			using (qubits = Qubit[3]) {
				using (y = Qubit[1]) {
					X(qubits[0]);
					// X(qubits[1]);
					// X(qubits[2]);
					// Solve(qubits, y[0]);
					DumpMachine(ToStringIFormat(0, "dump-0.\\.txt"));
					Reset(y[0]);
				}
				ResetAll(qubits);
			}
		}
	}
}