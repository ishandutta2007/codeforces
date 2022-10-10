namespace Solution {
	open Microsoft.Quantum.Intrinsic;
	open Microsoft.Quantum.Measurement;

	operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
		mutable res = Zero;
		using (qs = Qubit[2]) {
			H(qs[0]);
			CNOT(qs[0], qs[1]);
			(Controlled unitary)([qs[0]], qs[1]);
			CNOT(qs[0], qs[1]);
			H(qs[0]);
			set res = MResetZ(qs[0]);
		}
		return (res == Zero) ? 1 | 0;
	}
}