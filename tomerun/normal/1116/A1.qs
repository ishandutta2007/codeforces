namespace Solution
{
	open Microsoft.Quantum.Canon;
	open Microsoft.Quantum.Primitive;
	open Microsoft.Quantum.Extensions.Convert;
	open Microsoft.Quantum.Extensions.Diagnostics;
	open Microsoft.Quantum.Extensions.Math;
	open Microsoft.Quantum.Canon;

	operation Solve (qs : Qubit[]) : () {
		body {
			H(qs[0]);
			H(qs[1]);
			using (anc = Qubit[1]) {
				repeat {
					CCNOT(qs[0], qs[1], anc[0]);
					let outcome = M(anc[0]);
				}
				until(outcome == Zero)
				fixup {
					X(qs[0]);
					H(qs[0]);
					X(qs[1]);
					H(qs[1]);
					X(anc[0]);
				}
			}
		}
	}

	operation SolveTest () : () {
		body {
			using (qubits = Qubit[2]) {
				Solve(qubits);
				DumpMachine(ToStringIFormat(0, "dump-0.\\.txt"));
				ResetAll(qubits);
			}
		}
	}
}