namespace Solution {
	open Microsoft.Quantum.Math;
	open Microsoft.Quantum.Canon;
	open Microsoft.Quantum.Intrinsic;
	open Microsoft.Quantum.Diagnostics;
	
	operation Solve (t : Double, U : (Qubit => Unit is Adj + Ctl)) : Int {
		mutable x = 0;
		mutable w = 0.0;
		repeat {
			set w = w + t / 2.0;
			set x = x + 1;
		} until (Sin(w) * Sin(w) > 0.9);
		using (q = Qubit[2]) {
			mutable r = 0;
			for (o in 1..10) {
				for (i in 1..x) { U(q[0]); }
				CNOT(q[0], q[1]);
				if (M(q[1]) == One) { set r = 1; }
				Reset(q[0]);
				Reset(q[1]);
			}
			return r;
		}
	}

}