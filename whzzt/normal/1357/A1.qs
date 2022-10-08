namespace Solution {
	open Microsoft.Quantum.Canon;
	open Microsoft.Quantum.Intrinsic;
	open Microsoft.Quantum.Diagnostics;
	
	operation Solve (U : (Qubit[] => Unit is Adj+Ctl)) : Int {
		using (q = Qubit[2]) {
			X(q[0]);
			U(q);
			mutable r = 0;
			if (M(q[1]) == Zero) {
				set r = 1;
			}
			Reset(q[0]);
			Reset(q[1]);
			return r;
		}
	}
}