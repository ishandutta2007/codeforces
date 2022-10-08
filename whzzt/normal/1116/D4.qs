namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
	open Microsoft.Quantum.Extensions.Math;
	operation Set (target : Result, q : Qubit) : Unit {
		body (...) {
			if (M(q) != target) {
				X(q);
			}
		}
	}
	operation Apply (q : Qubit[], f : (((Qubit) => Unit) : Adjoint, Controlled)) : Unit {
		body (...) {
			let n = Length(q);
			for (i in 0 .. n - 1) {
				f(q[i]);
			}
		}
		adjoint auto;
		controlled auto;
		adjoint controlled auto;
	}
	operation Rotate (q : Qubit, g : Double) : Unit {
		body (...) {
			Ry(2.0 * ArcSin(g), q);
		}
		adjoint auto;
		controlled auto;
		adjoint controlled auto;
	}
	operation Majority (x : Qubit, y : Qubit, z : Qubit) : Unit {
		// x, z, (x + z) >= 2
		body (...) {
			Controlled X([x, z], (y));
			SWAP(y, z);
		}
		adjoint auto;
		controlled auto;
		adjoint controlled auto;
	}
	operation Addition (x : Qubit[]) : Unit {
		body (...) {
			let n = Length(x);
			using (y = Qubit[n + 1]) {
				X(y[n]);
				for (i in 0..n-1) {
					Majority(x[i], y[i], y[n]);
				}
				for (i in n-1..-1..0) {
					Adjoint Majority(x[i], y[i], y[n]);
					CNOT(y[n], x[i]);
				}
				X(y[n]);
			}
		}
		adjoint auto;
		controlled auto;
		adjoint controlled auto;
	}
    operation Solve (x : Qubit[]) : Unit {
        body (...) {
			let n = Length(x);
			Controlled Adjoint Addition([x[n-1]], (x[0..n-2]));
			X(x[n-1]);
			Controlled Addition([x[n-1]], (x[0..n-2]));
			X(x[n-1]);
			Apply(x[0..n-2], X);
			Controlled Apply([x[n-1]], (x[0..n-2], X));
			H(x[n-1]);
			Controlled Apply([x[n-1]], (x[0..n-2], X));
        }
    }
	function Trans(c : Int) : String {
		if (c == 0) { return "0"; }
		elif (c == 1) { return "1"; }
		elif (c == 2) { return "2"; }
		elif (c == 3) { return "3"; }
		elif (c == 4) { return "4"; }
		elif (c == 5) { return "5"; }
		elif (c == 6) { return "6"; }
		elif (c == 7) { return "7"; }
		elif (c == 8) { return "8"; }
		elif (c == 9) { return "9"; }
		else { return "Error"; }
	}
	operation Test() : String {
		body (...) {
			mutable C = new Int[8];
			for (i in 1..100) {
				using (q = Qubit[3]) {
					let Pos = 5;
					for (j in 0..2) {
						if (((Pos >>> j) &&& 1) == 1) {
							Set(One, q[j]);
						} else {
							Set(Zero, q[j]);
						}
					}
					Solve(q);
					mutable u = 0;
					let Q = [M(q[0]), M(q[1]), M(q[2])];
					mutable idx = 0;
					for (j in 0..2) {
						if (Q[j] == One) {
							set idx = idx + (1 <<< j);
						}
					}
					set C[idx] = C[idx] + 1;
					for (j in 0..2) { Set(Zero, q[j]); }
				}
			}
			mutable ret = "";
			for (c in 0..7) {
				mutable val = C[c];
				set ret = ret + Trans(val / 10);
				set ret = ret + Trans(val % 10);
				if (c != 7) { set ret = ret + ","; }
			}
			return ret;
		}
	}
}