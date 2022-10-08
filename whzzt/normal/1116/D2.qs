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
	operation Move (x : Qubit[]) : Unit {
		body (...) {
			let n = Length(x);
			for (i in 1..n-1) {
				SWAP(x[0], x[i]);
			}
		}
		adjoint auto;
		controlled auto;
		adjoint controlled auto;
	}
	operation Counter (x : Qubit[], y : Qubit[]) : Unit {
		body (...) {
			let n = Length(x);
			for (i in 0..n-1) {
				Controlled Move([x[i]], (y));
			}
		}
		adjoint auto;
		controlled auto;
		adjoint controlled auto;
	}
    operation Solve (x : Qubit[]) : Unit {
        body (...) {
			let n = Length(x);
			for (i in 0..n-1) {
				for (j in 0..i-1) {
					Controlled Rx([x[i]], (2.33333333, x[j]));
				}
			}
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
			mutable U = new Bool[][10];
			for (i in 0..9) {
				set U[i] = new Bool[3];
			}
			set U[0][0] = false; set U[0][1] = true; set U[0][2] = false;
			set U[1][0] = true; set U[1][1] = false; set U[1][2] = false;
			set U[2][0] = true; set U[2][1] = false; set U[2][2] = true;
			set U[3][0] = true; set U[3][1] = true; set U[3][2] = true;
			for (i in 1..100) {
				using (q = Qubit[3]) {
					Set(One, q[0]); Set(One, q[1]); Set(One, q[2]);
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