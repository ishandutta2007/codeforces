namespace Solution {
	open Microsoft.Quantum.Math;
	open Microsoft.Quantum.Canon;
	open Microsoft.Quantum.Intrinsic;
	open Microsoft.Quantum.Diagnostics;
	
	operation Solve (U : ((Double, Qubit) => Unit is Adj+Ctl)) : Int {
		using (q = Qubit[2]) {
			H(q[0]);
			H(q[1]);
			mutable r = 0;
			(Controlled U)([q[0]], (PI() * 2.0, q[1]));
			H(q[0]);
			if (M(q[0]) == Zero) {
				set r = 1;
			}
			Reset(q[0]);
			Reset(q[1]);
			return r;
		}
	}
}