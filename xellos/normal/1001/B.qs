namespace Solution {
	open Microsoft.Quantum.Primitive;
	open Microsoft.Quantum.Canon;

	operation Solve (qs : Qubit[], index : Int) : () {
		body {
			if(index%2 == 1) {
				X(qs[0]);
			}
			if(index/2 == 1) {
				X(qs[1]);
			}
			H(qs[0]);
			CNOT(qs[0], qs[1]);
		}
	}
}