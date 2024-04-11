namespace Solution {
	open Microsoft.Quantum.Convert;
	open Microsoft.Quantum.Diagnostics;
	open Microsoft.Quantum.Extensions.Convert;
	open Microsoft.Quantum.Math;
	open Microsoft.Quantum.Measurement;
	open Microsoft.Quantum.Canon;
	open Microsoft.Quantum.Intrinsic;

	operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
		using (q = Qubit())  {
			H(q);
			unitary(q);
			unitary(q);
			H(q);
			let res = MResetZ(q);
			return res == One ? 1 | 0;
		}
	}
}