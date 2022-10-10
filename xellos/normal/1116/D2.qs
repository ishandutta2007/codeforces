namespace Solution {
	open Microsoft.Quantum.Primitive;
	open Microsoft.Quantum.Canon;

	operation Solve (qs : Qubit[]) : Unit
	{
		for (i in Length(qs)-1..-1..0) {
			for (j in i+1..Length(qs)-1) {
				X(qs[j]);
			}
			for (j in 0..i-1) {
				(Controlled H)(qs[i..Length(qs)-1], qs[j]);
			}
			for (j in i+1..Length(qs)-1) {
				X(qs[j]);
			}
		}
	}
}