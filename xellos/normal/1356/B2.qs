namespace Solution {
	open Microsoft.Quantum.Intrinsic;
	open Microsoft.Quantum.Arithmetic;

	operation Solve (register : LittleEndian) : Unit is Adj+Ctl {
		let qs = register!;
		let N = Length(qs);
		for (i in 0..N-1) {
			X(qs[i]);
		}
		for (i in N-1..-1..1) {
			(Controlled X)(qs[0..i-1], qs[i]);
		}
		X(qs[0]);
		for (i in 0..N-1) {
			X(qs[i]);
		}
	}
}