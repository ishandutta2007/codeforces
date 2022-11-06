namespace Solution
{
	open Microsoft.Quantum.Canon;
	open Microsoft.Quantum.Primitive;
	open Microsoft.Quantum.Extensions.Convert;
	open Microsoft.Quantum.Extensions.Diagnostics;
	open Microsoft.Quantum.Extensions.Math;

	operation Solve (q : Qubit) : Int {
		body {
			let u = Random([1.0; 1.0]);
			if (u == 0) {
				H(q);
			}
			let r = M(q);
			if (r == One) {
				return u;
			} else {
				return -1;
			}
		}
	}

	operation SolveTest () : () {
		body {
			mutable count0 = 0;
			mutable count1 = 0;
			for (i in 0..999) {
				using (qubits = Qubit[1]) {
					H(qubits[0]);
					let res = Solve(qubits[0]);
					if (res == 1) {
						set count1 = count1 + 1;
					} elif (res == 0) {
						set count0 = count0 + 1;
					}
					// DumpMachine(ToStringIFormat(i, "dump-0.\\.txt"));
					ResetAll(qubits);
				}
			}
			Message($"count0:{count0} count1:{count1}");
		}
	}
}