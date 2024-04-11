namespace Solution {
	open Microsoft.Quantum.Canon;
	open Microsoft.Quantum.Intrinsic;
	open Microsoft.Quantum.Diagnostics;
	
	operation Solve (U : (Qubit[] => Unit is Adj+Ctl)) : Int {
		using (q = Qubit[2]) {
			X(q[0]);
			U(q);
			mutable r = 0;
			if (M(q[1]) == One) {
				if (M(q[0]) == One) {
					set r = 1;
				} else {
					set r = 3;
				}
			} else {
				using (p = Qubit[2]) {
					X(p[1]);
					U(p);
					if (M(p[0]) == One) {
						set r = 2;
					} else {
						set r = 0;
					}
					Reset(p[0]);
					Reset(p[1]);
				}
			}
			Reset(q[0]);
			Reset(q[1]);
			return r;
		}
	}
}