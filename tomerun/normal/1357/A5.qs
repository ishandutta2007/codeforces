namespace Solution {
	open Microsoft.Quantum.Arithmetic;
	open Microsoft.Quantum.Convert;
	open Microsoft.Quantum.Diagnostics;
	open Microsoft.Quantum.Extensions.Convert;
	open Microsoft.Quantum.Math;
	open Microsoft.Quantum.Measurement;
	open Microsoft.Quantum.Canon;
	open Microsoft.Quantum.Intrinsic;

	operation Solve (theta : Double, unitary : (Qubit => Unit is Adj+Ctl)) : Int {
		let ops = 200;
		mutable res = 0;
		using(q = Qubit()) {
			if (theta < PI() * 0.5) {
				let count = Floor(PI() / theta);
				for (i in 1..(ops / count)) {
					for (j in 1..count) {
						unitary(q);
					}
					if (MResetZ(q) == One) {
						set res = 1;
					}
				}
			} else {
				for (i in 1..ops) {
					unitary(q);
					if (MResetZ(q) == One) {
						set res = 1;
					}
				}
			}
			return res;
		}
	}
 
}