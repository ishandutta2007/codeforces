namespace Solution {
	open Microsoft.Quantum.Primitive;
	open Microsoft.Quantum.Canon;

	operation Solve (qs : Qubit[]) : Unit
	{
		CNOT(qs[2], qs[1]);
		X(qs[1]);
		(Controlled H)(qs[1..1], qs[2]);
		X(qs[1]);
		CNOT(qs[2], qs[1]);

		CNOT(qs[2], qs[1]);
		(Controlled X)(qs[0..1], qs[2]);
		(Controlled X)(qs[1..1], qs[2]);
		CNOT(qs[2], qs[1]);

		H(qs[0]);
	}
}