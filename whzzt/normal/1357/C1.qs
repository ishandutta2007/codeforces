namespace Solution {
	open Microsoft.Quantum.Canon;
	open Microsoft.Quantum.Intrinsic;
	open Microsoft.Quantum.Diagnostics;
	
	operation Solve (qs : Qubit[]) : Unit {
		using (q = Qubit[1]) {
			let N = Length(qs);
			repeat {
				for (i in 0..N-1) {
					Reset(qs[i]);
					H(qs[i]);
				}
				Reset(q[0]);
				(Controlled X)(qs[0..N-1], q[0]);
			} until (M(q[0]) == Zero);
			Reset(q[0]);
		}
	}
}