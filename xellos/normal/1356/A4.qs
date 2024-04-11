namespace Solution {
	open Microsoft.Quantum.Intrinsic;
	open Microsoft.Quantum.Measurement;

	operation Solve (unitary : (Qubit[] => Unit is Adj+Ctl)) : Int {
		mutable res = Zero;
		using (qs = Qubit[2]) {
			unitary(qs);
			set res = MResetZ(qs[1]);
		}
		return (res == Zero) ? 1 | 0;
	}
}