namespace Solution {
	open Microsoft.Quantum.Intrinsic;
	open Microsoft.Quantum.Measurement;

	operation Solve (qs : Qubit[]) : Unit {
		mutable st = Zero;
		using (c = Qubit()) {
			repeat {
				H(qs[0]);
				H(qs[1]);
				(Controlled X)(qs, c);
				(Controlled X)([qs[0]], c);
				(Controlled X)([qs[1]], c);
				set st = M(c);
			}
			until (st == One)
			fixup {
				ResetAll(qs);
			};
			Reset(c);
		}
	}
}