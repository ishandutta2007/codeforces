namespace Solution {
	open Microsoft.Quantum.Primitive;
	open Microsoft.Quantum.Canon;

	operation Solve (qs : Qubit[]) : Int {
		body {
			H(qs[0]);
			H(qs[1]);
			mutable result = 0;
			if(M(qs[0]) == One) {
				set result = result + 2;
			}
			if(M(qs[1]) == One) {
				set result = result + 1;
			}
			return result;
		}
	}
}