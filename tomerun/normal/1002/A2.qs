namespace Solution
{
	open Microsoft.Quantum.Canon;
	open Microsoft.Quantum.Primitive;
	open Microsoft.Quantum.Extensions.Convert;
	open Microsoft.Quantum.Extensions.Diagnostics;

	operation Solve (qs : Qubit[], bits : Bool[]) : () {
		body {
			H(qs[0]);
			for (i in 1..Length(qs) - 1) {
				if (bits[i]) {
					CNOT(qs[0], qs[i]);
				}
			}
		}
	}

	operation SolveTest () : () {
		body {
			for (i in 1..8) {
				mutable bits = new Bool[i];
				for (j in 0..2..i-1) {
					set bits[j] = true;
				}
				using (qubits = Qubit[i]) {
					Solve(qubits, bits);
					DumpMachine(ToStringIFormat(i, "dump-0.\\.txt"));
					ResetAll(qubits);
				}
			}
		}
	}
}