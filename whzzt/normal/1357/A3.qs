namespace Solution {
	open Microsoft.Quantum.Canon;
	open Microsoft.Quantum.Intrinsic;
	open Microsoft.Quantum.Diagnostics;
	
	operation Solve (U : (Qubit => Unit is Adj+Ctl)) : Int {
		using (q = Qubit[1]) {
			U(q[0]);
			X(q[0]);
			U(q[0]);
			mutable r = 0;
			if (M(q[0]) == One) {
				set r = 1;
			}
			Reset(q[0]);
			return r;
		}
	}
}