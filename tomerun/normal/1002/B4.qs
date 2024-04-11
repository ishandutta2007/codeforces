namespace Solution
{
	open Microsoft.Quantum.Canon;
	open Microsoft.Quantum.Primitive;
	open Microsoft.Quantum.Extensions.Convert;
	open Microsoft.Quantum.Extensions.Diagnostics;

	operation Solve (qs : Qubit[]) : Int {
		body {
			H(qs[1]);
			CNOT(qs[0], qs[1]);
			H(qs[0]);
			let res = MultiM(qs);
			return 3 - ResultAsInt(res);
		}
	}

	operation SolveTest (i : Int) : Int {
		body {
			mutable res = 0;
			using (qubits = Qubit[i]) {
				if (i % 3 == 0) {
					X(qubits[i - 1]);
				}
				set res = Solve(qubits);
				// DumpMachine(ToStringIFormat(i, "dump-0.\\.txt"));
				ResetAll(qubits);
			}
			return res;
		}
	}
}