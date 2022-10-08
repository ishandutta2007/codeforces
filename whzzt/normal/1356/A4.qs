namespace Solution {
	open Microsoft.Quantum.Canon;
	open Microsoft.Quantum.Intrinsic;
	open Microsoft.Quantum.Diagnostics;
	
	operation Solve (unitary : (Qubit[] => Unit is Adj+Ctl)) : Int {
		body(...){
			using (q = Qubit[2]){
				unitary(q);
				mutable x = 1;
				if (M(q[1]) == One) {
					set x = 0;
				}
				Reset(q[0]);
				Reset(q[1]);
				return x;
			}
		}
	}
}