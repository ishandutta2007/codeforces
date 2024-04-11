namespace Solution
{
	open Microsoft.Quantum.Canon;
	open Microsoft.Quantum.Primitive;
	open Microsoft.Quantum.Extensions.Convert;
	open Microsoft.Quantum.Extensions.Diagnostics;
	open Microsoft.Quantum.Extensions.Math;

	operation Solve (qs : Qubit[], bits : Bool[][]) : () {
		body {
			let N = Length(qs);
			mutable outcome = new Result[2];
			using (anc = Qubit[2]) {
				repeat {
					H(anc[0]);
					H(anc[1]);
					for (i in 0..3) {
						for (j in 0..N-1) {
							if (bits[i][j]) {
								CCNOT(anc[0], anc[1], qs[j]);
							}
						}
						X(anc[1]);
						if (i % 2 == 1) {
							X(anc[0]);
						}
					}
					ApplyToEach(H, anc);
					for (i in 0..1) {
						set outcome[i] = M(anc[i]);
					}
				}
				until(ForAll(IsResultZero, outcome))
				fixup {
					ResetAll(anc);
					ResetAll(qs);
				}
			}
		}
	}

	operation SolveTest () : () {
		body {
			using (qubits = Qubit[16]) {
				mutable bits = new Bool[][4];
				set bits[0] = new Bool[16];
				set bits[1] = new Bool[16];
				set bits[2] = new Bool[16];
				set bits[3] = new Bool[16];
				set bits[1][1] = true;
				set bits[2][4] = true;
				set bits[3][10] = true;
				set bits[3][15] = true;
				Solve(qubits, bits);
				DumpMachine(ToStringIFormat(0, "dump-0.\\.txt"));
				ResetAll(qubits);
			}
		}
	}
}