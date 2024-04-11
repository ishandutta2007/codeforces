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
	operation Generate (x : Qubit[]) : Unit {
		body (...) {
			let n = 3;
			Rotate(x[0], Sqrt(1.0 / 3.0));
			X(x[0]);
			Controlled Rotate([x[0]], (x[1], Sqrt(1.0 / 2.0)));
			X(x[0]);
			X(x[0]); X(x[1]);
			Controlled X(x[0..1], x[2]);
			X(x[0]); X(x[1]);
			Rz(ArcCos(-1.0) * (-4.0 / 3.0), x[1]);
			Rz(ArcCos(-1.0) * (-2.0 / 3.0), x[2]);
		}
		adjoint auto;
		controlled auto;
		adjoint controlled auto;
	}
	operation Generate_Q (x : Qubit[]) : Unit {
		body (...) {
			let n = 3;
			Rotate(x[0], Sqrt(1.0 / 3.0));
			X(x[0]);
			Controlled Rotate([x[0]], (x[1], Sqrt(1.0 / 2.0)));
			X(x[0]);
			X(x[0]); X(x[1]);
			Controlled X(x[0..1], x[2]);
			X(x[0]); X(x[1]);
			Rz(ArcCos(-1.0) * (-2.0 / 3.0), x[1]);
			Rz(ArcCos(-1.0) * (-4.0 / 3.0), x[2]);
		}
		adjoint auto;
		controlled auto;
		adjoint controlled auto;
	}
	operation Solve (x : Qubit[]) : Int {
		body (...) {
			Adjoint Generate(x);
			if (M(x[0]) == Zero) {
				if (M(x[1]) == Zero) {
					if (M(x[2]) == Zero) {
						return 0;
					}
				}
			}
			return 1;
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
					if ((i &&& 1) == 0) {
						Generate(q);
					} else {
						Generate_Q(q);
					}
					let w = Solve(q);
					let idx = w * 2 + (i &&& 1);
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