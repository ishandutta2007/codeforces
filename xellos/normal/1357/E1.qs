namespace Solution {
	open Microsoft.Quantum.Arithmetic;
	open Microsoft.Quantum.Intrinsic;
	open Microsoft.Quantum.Canon;

	operation Solve (p : Int, inp : LittleEndian) : Unit is Adj+Ctl {
		for (i in 1..(p&&&3)) {
			QFTLE(inp);
		}
	}
}