namespace Solution {
	open Microsoft.Quantum.Intrinsic;
	open Microsoft.Quantum.Measurement;
	open Microsoft.Quantum.Arithmetic;

	operation Solve (qs : Qubit[], parity : Int) : Unit {
		mutable st = -1;
		let N = Length(qs);
		using (c = Qubit()) {
			repeat {
				for(i in 0..N-1) {
					H(qs[i]);
				}
				for(i in 0..N-1) {
					CNOT(qs[i], c);
				}
				set st = (M(c) == One) ? 1 | 0;
			}
			until (st == parity)
			fixup {
				ResetAll(qs);
				Reset(c);
			};
			Reset(c);
		}
	}
}