namespace Solution {
	open Microsoft.Quantum.Intrinsic;
	open Microsoft.Quantum.Arithmetic;

	operation Solve (inq : Qubit[], outq : Qubit) : Unit is Adj+Ctl {
		body (...) {
			let N = Length(inq);
			for (i in 0..(2^N)-1) {
				mutable diff = 0;
				for (j in 0..N-1) {
					set diff = diff + ((i>>>j)&&&1);
				}
				if (diff*2 == N) {
					for (j in 0..N-1) {
						if (((i>>>j)&&&1) == 1) {
							X(inq[j]);
						}
					}
					(Controlled X)(inq, outq);
					for (j in 0..N-1) {
						if (((i>>>j)&&&1) == 1) {
							X(inq[j]);
						}
					}
				}
			}
		}

		adjoint self;
	}
}