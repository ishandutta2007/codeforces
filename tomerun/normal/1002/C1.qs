namespace Solution
{
	open Microsoft.Quantum.Canon;
	open Microsoft.Quantum.Primitive;
	open Microsoft.Quantum.Extensions.Convert;
	open Microsoft.Quantum.Extensions.Diagnostics;
	open Microsoft.Quantum.Extensions.Math;

	operation Solve (q : Qubit) : Int {
		body {
			Ry(PI() / 4.0, q);
			let r = M(q);
			if (r == One) {
				return 1;
			} else {
				return 0;
			}
		}
	}

	operation SolveTest () : () {
		body {
			mutable count = 0;
			for (i in 0..999) {
				using (qubits = Qubit[1]) {
					H(qubits[0]);
					let res = Solve(qubits[0]);
					if (res == 1) {
						set count = count + 1;
					}
					// DumpMachine(ToStringIFormat(i, "dump-0.\\.txt"));
					ResetAll(qubits);
				}
			}
			Message($"count:{count}");
		}
	}
}