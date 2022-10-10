namespace Solution {
	open Microsoft.Quantum.Intrinsic;
	open Microsoft.Quantum.Measurement;
	open Microsoft.Quantum.Math;

	operation Solve (unitary : ((Double, Qubit) => Unit is Adj+Ctl)) : Int {
		mutable res = Zero;
		using (qs = Qubit[2]) {
			H(qs[0]);
			(Controlled unitary)([qs[0]], (2.*PI(), qs[1]));
			H(qs[0]);
			set res = MResetZ(qs[0]);
		}
		return (res == Zero) ? 1 | 0;
	}
}