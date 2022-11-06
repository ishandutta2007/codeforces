namespace Solution
{
	open Microsoft.Quantum.Canon;
	open Microsoft.Quantum.Primitive;
	open Microsoft.Quantum.Extensions.Convert;
	open Microsoft.Quantum.Extensions.Diagnostics;
	open Microsoft.Quantum.Extensions.Math;

	operation Solve (qs : Qubit[]) : () {
		body {
			let N = Length(qs);
			X(qs[0]);
			if (N == 1) {
				return ();
			}
			mutable l = 1;
			repeat {
				H(qs[l]);
				for (i in 1..l - 1) {
					CCNOT(qs[i], qs[l], qs[l + i]);
					CNOT(qs[l + i], qs[i]);
					CNOT(qs[l + i], qs[l]);
				}
				CNOT(qs[l], qs[0]);
				set l = l * 2;
			} until l == N
			fixup {
			}
		}
	}

	operation SolveTest () : () {
		body {
			using (qubits = Qubit[1]) {
				Solve(qubits);
				DumpMachine(ToStringIFormat(0, "dump-0.\\.txt"));
				ResetAll(qubits);
			}
		}
	}
}