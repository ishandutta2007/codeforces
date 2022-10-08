namespace Solution {
	open Microsoft.Quantum.Canon;
	open Microsoft.Quantum.Intrinsic;
	open Microsoft.Quantum.Diagnostics;
	
	operation Solve (U : (Qubit => Unit is Adj+Ctl)) : Int {
		body(...){
			using (q = Qubit[2]){
				H(q[0]);
				H(q[1]);
				Controlled U([q[0]], q[1]);
				H(q[0]);
				mutable x = 0;
				if (M(q[0]) != M(q[1])) {
					set x = 1;
				}
				Reset(q[0]);
				Reset(q[1]);
				return x;
			}
		}
	}
}