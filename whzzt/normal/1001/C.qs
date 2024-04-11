namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

	operation Solve(qs : Qubit[]) : Unit {
		body {
			let N = Length(qs);
			H(qs[0]);
			for (i in 1 .. N - 1) {
				CNOT(qs[i - 1], qs[i]);
			}
		}
	}

	operation Test() : Int {
		body {
			mutable C = 0;
			using (q = Qubit[5]) {
				for (i in 0 .. 4) {
					let cur = M(q[i]);
					if (cur != Zero) {
						X(q[i]);
					}
				}
				for (i in 1 .. 100) {
					Solve(q);
					let state = M(q[0]);
					mutable u = 0;
					for (j in 1 .. 4) {
						if (M(q[j]) != state) {
							set u = 1;
						}
					}
					if (u == 0) {
						set C = C + 1;
					}
				}
			}
			return C;
		}
	}
}