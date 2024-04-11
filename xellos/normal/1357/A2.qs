namespace Solution {
	open Microsoft.Quantum.Intrinsic;
	open Microsoft.Quantum.Measurement;

	operation Solve (unitary : (Qubit[] => Unit is Adj+Ctl)) : Int {
		mutable ans = 0;
		using (qs = Qubit[2]) {
			X(qs[1]);
			unitary(qs);
			if (MResetZ(qs[0]) == One) {
				set ans = ans + 2;
			}
			Reset(qs[1]);
		}
		using (qs = Qubit[2]) {
			X(qs[0]);
			unitary(qs);
			if (MResetZ(qs[1]) == One) {
				set ans = ans + 1;
			}
			Reset(qs[0]);
		}
		return ans;
	}
}