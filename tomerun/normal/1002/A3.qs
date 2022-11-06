namespace Solution
{
	open Microsoft.Quantum.Canon;
	open Microsoft.Quantum.Primitive;
	open Microsoft.Quantum.Extensions.Convert;
	open Microsoft.Quantum.Extensions.Diagnostics;

	operation Solve (qs : Qubit[], bits0 : Bool[], bits1 : Bool[]) : () {
		body {
			mutable axis = 0;
			for (i in 0..Length(qs) - 1) {
				if (bits0[i] != bits1[i]) {
					set axis = i;
				}
			}
			H(qs[axis]);
			for (i in 0..Length(qs) - 1) {
				if (i != axis) {
					if (bits0[i]) {
						if (bits1[i]) {
							X(qs[i]);
						} else {
							CNOT(qs[axis], qs[i]);
							if (bits0[axis] != bits0[i]) {
								X(qs[i]);
							}
						}
					} else {
						if (bits1[i]) {
							CNOT(qs[axis], qs[i]);
							if (bits0[axis] != bits0[i]) {
								X(qs[i]);
							}
						} else {
							//							
						}
					}
				}
			}
		}
	}

	operation SolveTest () : () {
		body {
			for (i in 4..4..8) {
				mutable bits0 = new Bool[i];
				mutable bits1 = new Bool[i];
				for (j in 0..4..i-1) {
					set bits0[j] = true;
					set bits0[j+2] = true;
					set bits1[j] = true;
					set bits1[j+1] = true;
				}
				using (qubits = Qubit[i]) {
					Solve(qubits, bits0, bits1);
					DumpMachine(ToStringIFormat(i, "dump-0.\\.txt"));
					ResetAll(qubits);
				}
			}
		}
	}
}