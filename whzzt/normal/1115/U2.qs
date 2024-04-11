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
    operation Solve (qs : Qubit[]) : Unit {
        body (...) {
			Ry(2.0 * ArcSin(1.0 / Sqrt(3.0)), qs[0]);
			X(qs[0]);
			Controlled H([qs[0]], qs[1]);
			X(qs[0]);
        }
    }
	operation Test() : Int {
		body (...) {
			mutable C = new Int[4];
			for (i in 1..100) {
				using (q = Qubit[2]) {
					Solve(q);
					mutable u = 0;
					if (M(q[0]) == One) { set u = u + 2; }
					if (M(q[1]) == One) { set u = u + 1; }
					set C[u] = C[u] + 1;
					for (j in 0..1) { Set(Zero, q[j]); }
				}
			}
			return C[0] * 1000000 + C[1] * 10000 + C[2] * 100 + C[3];
		}
	}
}