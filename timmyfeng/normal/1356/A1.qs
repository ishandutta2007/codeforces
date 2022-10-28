namespace Solution {
    open Microsoft.Quantum.Intrinsic;

    operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
		mutable res = Zero;
		using (q = Qubit()) {
			unitary(q);
			set res = M(q);
			Reset(q);
		}
		return res == Zero ? 0 | 1;
    }
}