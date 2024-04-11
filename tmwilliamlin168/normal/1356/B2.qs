namespace Solution {
	open Microsoft.Quantum.Intrinsic;
	open Microsoft.Quantum.Measurement;
	open Microsoft.Quantum.Math;
	open Microsoft.Quantum.Convert;
	open Microsoft.Quantum.Canon;
	open Microsoft.Quantum.Arithmetic;
	open Microsoft.Quantum.Diagnostics;

	operation Solve (register : LittleEndian) : Unit is Adj+Ctl {
		let n=Length(register!);
		if(n>0) {
	    (ControlledOnInt(0, Solve))(register![0..0], LittleEndian(register![1..n-1]));
		X(register![0]);
		}
	}
}