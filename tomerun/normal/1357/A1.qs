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
			let res = M(qs[0]);
			ResetAll(qs);
			return res == One ? 1 | 0;
		}
	}
}