namespace Solution {
	open Microsoft.Quantum.Arithmetic;
	open Microsoft.Quantum.Convert;
	open Microsoft.Quantum.Diagnostics;
	open Microsoft.Quantum.Extensions.Convert;
	open Microsoft.Quantum.Math;
	open Microsoft.Quantum.Measurement;
	open Microsoft.Quantum.Canon;
	open Microsoft.Quantum.Intrinsic;

	operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
		using(qs = Qubit[2]) {
			H(qs[0]);
			CNOT(qs[0], qs[1]);
			unitary(qs[1]);
			CNOT(qs[1], qs[0]);
			H(qs[1]);
			let res0 = M(qs[0]);
			let res1 = M(qs[1]);
			ResetAll(qs);
			if (res0 == Zero) {
				return res1 == Zero ? 0 | 3;
			} else {
				return res1 == Zero ? 1 | 2;
			}
		}
	}
 
}