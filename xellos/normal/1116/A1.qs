namespace Solution {
	open Microsoft.Quantum.Primitive;
	open Microsoft.Quantum.Canon;

	operation Solve (qs : Qubit[]) : Unit
	{
		let coef = [1.0, 1.0, 1.0, 0.0];
		let op = StatePreparationPositiveCoefficients(coef);
		let qsBE = BigEndian(qs);
		op(qsBE);
	}
}