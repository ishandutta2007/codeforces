namespace Solution {
	open Microsoft.Quantum.Math;
	open Microsoft.Quantum.Canon;
	open Microsoft.Quantum.Convert;
	open Microsoft.Quantum.Intrinsic;
	open Microsoft.Quantum.Arithmetic;
	open Microsoft.Quantum.Diagnostics;
	
	operation Solve (p : Int, a : LittleEndian) : Unit is Adj + Ctl {
		for (i in 1..p%4) {
			QFTLE(a);
		}
	}
}