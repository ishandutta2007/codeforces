namespace Solution {
	open Microsoft.Quantum.Math;
	open Microsoft.Quantum.Canon;
	open Microsoft.Quantum.Intrinsic;
	open Microsoft.Quantum.Diagnostics;
	open Microsoft.Quantum.Convert;
	
	operation Solve (U : (Qubit => Unit is Adj + Ctl)) : Int {
		using (q = Qubit[2]) {
			// Distinguish U^2 and I
			H(q[0]);
			CNOT(q[0], q[1]);
			(Controlled U)([q[0]], q[1]);
			(Controlled U)([q[0]], q[1]);
			CNOT(q[0], q[1]);
			H(q[0]);
			mutable b0 = 0;
			if (M(q[0]) == One) {
				set b0 = 1;
			}
			Reset(q[0]);
			Reset(q[1]);
			mutable b1 = 0;
			H(q[0]);
			CNOT(q[0], q[1]);
			(Controlled U)([q[0]], q[1]);
			if (b0 == 0) {
				// Distinguish Y and -Y
				S(q[0]);
				H(q[0]);
				if (M(q[0]) == One) {
					set b1 = 2;
				}
			} else {
				// Distinguish -XZ and XZ
				H(q[0]);
				if (M(q[0]) == One) {
					set b1 = 2;
				}
			}
			Reset(q[0]);
			Reset(q[1]);
			return b0 + b1;
		}
	}
}