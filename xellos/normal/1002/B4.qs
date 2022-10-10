namespace Solution {
	open Microsoft.Quantum.Primitive;
	open Microsoft.Quantum.Canon;

	operation Solve (qs : Qubit[]) : Int {
		body {
			H(qs[0]);
			CNOT(qs[0], qs[1]);
			H(qs[0]);
			mutable result = 0;
			if(M(qs[0]) == Zero) {
				set result = result + 2;
			}
			if(M(qs[1]) == Zero) {
				set result = result + 1;
			}
			return result;
		}
	}
}