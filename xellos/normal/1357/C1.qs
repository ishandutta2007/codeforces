namespace Solution {
	open Microsoft.Quantum.Intrinsic;
	open Microsoft.Quantum.Measurement;
	open Microsoft.Quantum.Arithmetic;

	operation Solve (qs : Qubit[]) : Unit {
		mutable st = Zero;
		let N = Length(qs);
		using (c = Qubit()) {
			repeat {
				for(i in 0..N-1) {
					H(qs[i]);
				}
				for(i in 0..N-1) {
					X(qs[i]);
					(Controlled X)(qs[0..i], c);
					X(qs[i]);
				}
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