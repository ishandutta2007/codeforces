namespace Solution {
	open Microsoft.Quantum.Primitive;
	open Microsoft.Quantum.Canon;

	operation TestRemainder (r : Int, x : Qubit[], y : Qubit) : Unit {
		body (...) {
			let N = Length(x);
			if (N <= 3) {
				if (r == 1) {
					if (N == 1) {
						CNOT(x[0], y);
					}
					elif (N == 2) {
						CNOT(x[0], x[1]);
						CNOT(x[1], y);
						CNOT(x[0], x[1]);
					}
					else {
						for (i in 0..N-1) {
							X(x[i]);
						}
						for (i in 0..N-1) {
							X(x[i]);
							(Controlled X)(x, y);
							X(x[i]);
						}
						for (i in 0..N-1) {
							X(x[i]);
						}
					}
				}
				elif (r == 2) {
					if (N == 1) {}
					elif (N == 2) {
						(Controlled X)(x, y);
					}
					else {
						for (i in 0..N-1) {
							X(x[i]);
							(Controlled X)(x, y);
							X(x[i]);
						}
					}
				}
				else {
					if (N == 3) {
						(Controlled X)(x, y);
					}
					for (i in 0..N-1) {
						X(x[i]);
					}
					(Controlled X)(x, y);
					for (i in 0..N-1) {
						X(x[i]);
					}
				}
			}
			else {
				let g0 = x[0..2];
				let g1 = x[3..N-1];
				using (q = Qubit()) {
					if (r == 1) {
						TestRemainder(0, g0, q);
						(Controlled TestRemainder)([q], (1, g1, y));
						TestRemainder(0, g0, q);
						TestRemainder(1, g0, q);
						(Controlled TestRemainder)([q], (0, g1, y));
						TestRemainder(1, g0, q);
						TestRemainder(2, g0, q);
						(Controlled TestRemainder)([q], (2, g1, y));
						TestRemainder(2, g0, q);
					}
					elif (r == 2) {
						TestRemainder(0, g0, q);
						(Controlled TestRemainder)([q], (2, g1, y));
						TestRemainder(0, g0, q);
						TestRemainder(1, g0, q);
						(Controlled TestRemainder)([q], (1, g1, y));
						TestRemainder(1, g0, q);
						TestRemainder(2, g0, q);
						(Controlled TestRemainder)([q], (0, g1, y));
						TestRemainder(2, g0, q);
					}
					else {
						TestRemainder(0, g0, q);
						(Controlled TestRemainder)([q], (0, g1, y));
						TestRemainder(0, g0, q);
						TestRemainder(1, g0, q);
						(Controlled TestRemainder)([q], (2, g1, y));
						TestRemainder(1, g0, q);
						TestRemainder(2, g0, q);
						(Controlled TestRemainder)([q], (1, g1, y));
						TestRemainder(2, g0, q);
					}
				}
			}
		}
		adjoint auto;
		controlled auto;
		controlled adjoint auto;
	}

	operation Solve (x : Qubit[], y : Qubit) : Unit
	{
		body (...) {
			TestRemainder(0, x, y);
		}
		adjoint auto;
	}
}