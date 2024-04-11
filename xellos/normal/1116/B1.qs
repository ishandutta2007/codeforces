namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Extensions.Math;

    operation Solve (qs : Qubit[]) : Int
    {
//      |100> + om   |010> + om^2 |001> = |100> + om  |010> + om* |001>
//      |100> + om^2 |010> + om   |001> = |100> + om* |010> + om  |001>
		X(qs[0]);
//      |000> + om  |110> + om* |101>
//      |000> + om* |110> + om  |101>
		X(qs[1]);
		CCNOT(qs[0], qs[1], qs[2]);
		X(qs[1]);
//      (|00> + om  |11> + om* |10>) |0>
//      (|00> + om* |11> + om  |10>) |0>
		let theta = 2./3. * PI();
		(Controlled R1)([qs[0]], (theta, qs[1]));
//      (|00> + om* (|11> + |10>)) |0>
//      (|00> + |11> + om |10>) |0>
		R1(theta, qs[0]);
//      (|00> + |11> + |10>) |0>
//      (|00> + om |11> + om* |10>) |0>
		(Controlled H)([qs[0]], qs[1]);
//      (|0> + sqrt2 |1>) |00>
//      (|00> + (om+om*)/sqrt2 |10> + (om*-om)/sqrt2 |11>) |0> = (|00> - 1/sqrt2 |10> - i sqrt3 |11>) |0>
		let alpha = -2.0 * ArcTan(Sqrt(2.0));
		Ry(alpha, qs[0]);
//      |000>
//      (|00> - sqrt2 |10> - 1/sqrt2 |10> - |00> - i sqrt3 |11> - i sqrt6 |01>) |0> = - (3/sqrt2 |10> + i sqrt3 |11> + i sqrt6 |01>) |0>
		let qsLE = LittleEndian(qs[0..1]);
		mutable res = MeasureInteger(qsLE);
		if (res > 0) {
			set res = 1;
		}
		return res;
    }
}