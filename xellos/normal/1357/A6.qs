namespace Solution {
	open Microsoft.Quantum.Intrinsic;
	open Microsoft.Quantum.Measurement;
	open Microsoft.Quantum.Arithmetic;

	operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
		mutable ans = 0;
		using (qs = Qubit[2]) {
			// Bell pair
			H(qs[0]);
			CNOT(qs[0], qs[1]);
			X(qs[1]);
			unitary(qs[1]);
			CNOT(qs[0], qs[1]);
			H(qs[0]);
			CNOT(qs[0], qs[1]);
			X(qs[1]);
			SWAP(qs[0], qs[1]);
			set ans = MeasureInteger(LittleEndian(qs));
			ResetAll(qs);
		}
		return ans;
	}
}