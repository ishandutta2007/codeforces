namespace Solution {
	open Microsoft.Quantum.Convert;
	open Microsoft.Quantum.Diagnostics;
	open Microsoft.Quantum.Extensions.Convert;
	open Microsoft.Quantum.Math;
	open Microsoft.Quantum.Measurement;
	open Microsoft.Quantum.Canon;
	open Microsoft.Quantum.Intrinsic;

	operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
		using ((control, target) = (Qubit(), Qubit()))  {
			H(control);
			CNOT(control, target);
			Controlled unitary([control], target);
			CNOT(control, target);
			H(control);
			let res = MResetZ(control);
			Reset(target);
			return res == One ? 0 | 1;
		}
	}
}