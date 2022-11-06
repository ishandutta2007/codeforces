namespace Solution {
	open Microsoft.Quantum.Arithmetic;
	open Microsoft.Quantum.Convert;
	open Microsoft.Quantum.Diagnostics;
	open Microsoft.Quantum.Extensions.Convert;
	open Microsoft.Quantum.Math;
	open Microsoft.Quantum.Measurement;
	open Microsoft.Quantum.Canon;
	open Microsoft.Quantum.Intrinsic;

	operation Solve (register : LittleEndian) : Unit is Adj+Ctl {
		let qs = register!;
		let L = Length(qs);
		X(qs[0]);
		for (i in 1..(L - 1)) {
			Controlled X(qs[0..(i-1)], qs[i]);
		}
	}
}