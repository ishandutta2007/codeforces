namespace Solution {
	open Microsoft.Quantum.Arithmetic;
	open Microsoft.Quantum.Convert;
	open Microsoft.Quantum.Diagnostics;
	open Microsoft.Quantum.Extensions.Convert;
	open Microsoft.Quantum.Math;
	open Microsoft.Quantum.Measurement;
	open Microsoft.Quantum.Canon;
	open Microsoft.Quantum.Intrinsic;

	operation Solve (unitary : (Qubit[] => Unit is Adj+Ctl)) : Int {
		using (qs = Qubit[2]) {
			X(qs[1]);
			unitary(qs);
			let res1 = MResetZ(qs[0]);
			let res2 = MResetZ(qs[1]);
			if (res1 == One) {
				return res2 == One ? 2 | 3;
			}
		}
		using (qs = Qubit[2]) {
			X(qs[0]);
			unitary(qs);
			Reset(qs[0]);
			let res2 = MResetZ(qs[1]);
			return res2 == One ? 1 | 0;
		}
	}
}