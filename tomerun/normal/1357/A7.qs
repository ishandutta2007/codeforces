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
			Controlled unitary([qs[0]], qs[1]);
			Controlled unitary([qs[0]], qs[1]);
			H(qs[0]);
			let res0 = MResetZ(qs[0]);
			Reset(qs[1]);
			if (res0 == One) {
				H(qs[0]);
				Controlled unitary([qs[0]], qs[1]);
				CNOT(qs[1], qs[0]);
				H(qs[1]);
				let res1 = MResetZ(qs[1]);
				return res1 == Zero ? 3 | 1;
			} else {
				H(qs[0]);
				Controlled unitary([qs[0]], qs[1]);
				S(qs[1]);
				CNOT(qs[1], qs[0]);
				H(qs[1]);
				let res1 = MResetZ(qs[1]);
				return res1 == Zero ? 2 | 0;
			}
		}
	}
 
	operation SolveTest () : Int {
		Message($"{Solve(y)}");
		Message($"{Solve(ym)}");
		Message($"{Solve(xz)}");
		Message($"{Solve(xzm)}");
		return 0;
	}

	operation y(q : Qubit) : Unit is Adj+Ctl {
		Y(q);
	}
	operation ym(q : Qubit) : Unit is Adj+Ctl {
		Y(q);
		Rz(PI() * 2.0, q);
	}
	operation xz(q : Qubit) : Unit is Adj+Ctl {
		Z(q);
		X(q);
	}
	operation xzm(q : Qubit) : Unit is Adj+Ctl {
		Z(q);
		X(q);
		Rz(PI() * 2.0, q);
	}
}