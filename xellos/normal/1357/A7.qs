namespace Solution {
	open Microsoft.Quantum.Intrinsic;
	open Microsoft.Quantum.Measurement;
	open Microsoft.Quantum.Arithmetic;

	operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
		mutable imag = 0;
		using (qs = Qubit[2]) {
			H(qs[0]);
			(Controlled Y)([qs[0]], qs[1]);
			(Controlled unitary)([qs[0]], qs[1]);
			(Controlled Y)([qs[0]], qs[1]);
			(Controlled unitary)([qs[0]], qs[1]);
			H(qs[0]);
			set imag = (MResetZ(qs[0]) == One) ? 1 | 0;
		}
		mutable ans = 0;
		if (imag == 0) {
			using (qs = Qubit[2]) {
				H(qs[0]);
				(Controlled Y)([qs[0]], qs[1]);
				(Controlled unitary)([qs[0]], qs[1]);
				H(qs[0]);
				set ans = imag + ((MResetZ(qs[0]) == One) ? 2 | 0);
			}
		}
		else {
			using (qs = Qubit[2]) {
				H(qs[0]);
				(Controlled X)([qs[0]], qs[1]);
				(Controlled unitary)([qs[0]], qs[1]);
				H(qs[0]);
				set ans = imag + ((MResetZ(qs[0]) == One) ? 2 | 0);
			}
		}

		return ans;
	}
}