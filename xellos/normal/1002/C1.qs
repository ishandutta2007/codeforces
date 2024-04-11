namespace Solution {
	open Microsoft.Quantum.Primitive;
	open Microsoft.Quantum.Canon;

	operation Solve (q : Qubit) : Int {
		body {
			S(q);
			RFrac(PauliX, 1, 3, q);
			if(M(q) == Zero) {
				return 0;
			}
			return 1;
		}
	}
}