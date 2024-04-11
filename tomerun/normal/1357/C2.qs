namespace Solution {
	open Microsoft.Quantum.Arithmetic;
	open Microsoft.Quantum.Convert;
	open Microsoft.Quantum.Diagnostics;
	open Microsoft.Quantum.Extensions.Convert;
	open Microsoft.Quantum.Math;
	open Microsoft.Quantum.Measurement;
	open Microsoft.Quantum.Canon;
	open Microsoft.Quantum.Intrinsic;

	operation Solve (qs : Qubit[], parity : Int) : Unit {
		if (parity == 1) {
			X(qs[0]);
		}
		let N = Length(qs);
		for (i in 1..(N - 1)) {
			H(qs[i]);
			CNOT(qs[i], qs[0]);
		}
	}
 
}