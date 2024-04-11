namespace Solution
{
	open Microsoft.Quantum.Canon;
	open Microsoft.Quantum.Primitive;
	open Microsoft.Quantum.Extensions.Convert;
	open Microsoft.Quantum.Extensions.Diagnostics;

	operation Solve (qs : Qubit[]) : Int {
		body {
			mutable res = Zero;
			using (reg = Qubit[1]) {
				for (i in 0..Length(qs) - 1) {
					CNOT(qs[i], reg[0]);
				}
				set res = M(reg[0]);
				Reset(reg[0]);
			}
			if (res == Zero) {
				return 0;
			} else {
				return 1;
			}
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