namespace Solution {
	open Microsoft.Quantum.Math;
	open Microsoft.Quantum.Canon;
	open Microsoft.Quantum.Intrinsic;
	open Microsoft.Quantum.Diagnostics;
	open Microsoft.Quantum.Convert;
	
	operation Solve (U : (Qubit => Unit is Adj + Ctl)) : Int {
		using (q = Qubit[2]) {
			H(q[0]);
			CNOT(q[0], q[1]);
			U(q[1]);
			mutable m0 = 0;
			using (w = Qubit[1]) {
				CNOT(q[0], w[0]);
				CNOT(q[1], w[0]);
				if (M(w[0]) == One) { set m0 = 1; }
				Reset(w[0]);
			}
			CNOT(q[0], q[1]);
			H(q[0]);
			mutable res = 0;
			if (m0 == 0) {
				if (M(q[0]) == Zero) { set res = 0; } else { set res = 3; }
			} else {
				if (M(q[0]) == Zero) { set res = 1; } else { set res = 2; }
			}
			Reset(q[0]);
			Reset(q[1]);
			return res;
		}
	}
}