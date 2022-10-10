namespace Solution {
	open Microsoft.Quantum.Intrinsic;
	open Microsoft.Quantum.Measurement;

	operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
		mutable res = Zero;
		using (q = Qubit()) {
			H(q);
			unitary(q);
			H(q);
			set res = MResetZ(q);
		}
		return (res == Zero) ? 0 | 1;
	}
}