namespace Solution {
	open Microsoft.Quantum.Arithmetic;
	open Microsoft.Quantum.Convert;
	open Microsoft.Quantum.Diagnostics;
	open Microsoft.Quantum.Extensions.Convert;
	open Microsoft.Quantum.Math;
	open Microsoft.Quantum.Measurement;
	open Microsoft.Quantum.Canon;
	open Microsoft.Quantum.Intrinsic;

	operation Solve (unitary : ((Double, Qubit) => Unit is Adj+Ctl)) : Int {
		using (qs = Qubit[2]) {
			H(qs[0]);
			Controlled X([qs[0]], qs[1]);
			Controlled unitary([qs[0]], (PI() * 2.0, qs[1]));
			Controlled X([qs[1]], qs[0]);
			H(qs[1]);
			let res = MResetZ(qs[1]);
			return res == Zero ? 1 | 0;
		}
	}

}