namespace Solution {
	open Microsoft.Quantum.Canon;
	open Microsoft.Quantum.Intrinsic;
	open Microsoft.Quantum.Diagnostics;
	
	operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
		body(...){
			using (q = Qubit[1]){
				unitary(q[0]);
				mutable x = 0;
				if (M(q[0]) == One) {
					set x = 1;
				}
				Reset(q[0]);
				return x;
			}
		}
	}
}