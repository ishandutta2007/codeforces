namespace Solution {
	open Microsoft.Quantum.Arithmetic;
	open Microsoft.Quantum.Intrinsic;
	open Microsoft.Quantum.Canon;
	open Microsoft.Quantum.Math;
	open Microsoft.Quantum.Convert;

	operation SplitEigen (qs : Qubit[]) : Unit is Adj+Ctl {
		let N = Length(qs)-2;
		H(qs[0]);
		(Controlled QFTLE)([qs[0]], LittleEndian(qs[2..N+1]));
		H(qs[1]);
		(Controlled QFTLE)([qs[1]], LittleEndian(qs[2..N+1]));
		(Controlled QFTLE)([qs[1]], LittleEndian(qs[2..N+1]));
		H(qs[1]);
		(Controlled S)([qs[1]], qs[0]);
		H(qs[0]);
	}

	operation Solve (p : Int, inp : LittleEndian) : Unit is Adj+Ctl {
		using (qs = Qubit[2]) {
			SplitEigen(qs + (inp!));
			R1(PI() / IntAsDouble(p), qs[0]);
			R1(-.5 * PI() / IntAsDouble(p), qs[1]);
			(Adjoint SplitEigen)(qs + (inp!));
		}
	}
}