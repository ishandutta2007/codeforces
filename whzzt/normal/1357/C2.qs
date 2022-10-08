namespace Solution {
	open Microsoft.Quantum.Canon;
	open Microsoft.Quantum.Intrinsic;
	open Microsoft.Quantum.Diagnostics;
	
	operation Solve (qs : Qubit[], parity : Int) : Unit {
		using (q = Qubit[1]) {
			let N = Length(qs);
			repeat {
				Reset(q[0]);
				if (parity == 1) {
					X(q[0]);
				}
				for (i in 0..N-1) {
					Reset(qs[i]);
					H(qs[i]);
					CNOT(qs[i], q[0]);
				}
			} until (M(q[0]) == Zero);
			Reset(q[0]);
		}
	}
}