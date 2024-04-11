namespace Solution {
	open Microsoft.Quantum.Primitive;
	open Microsoft.Quantum.Canon;

	operation Solve (q : Qubit) : Int {
		body {
			mutable answer = -1;
			using(test = Qubit[2]) {
				H(test[0]);
				CCNOT(q, test[0], test[1]);
				if(M(test[1]) == One) {
					set answer = 1;
				}
				else {
					H(q);
					if(M(q) == One) {
						if(M(test[0]) == Zero) {
							set answer = 0;
						}
					}
				}
				Reset(test[0]);
				Reset(test[1]);
			}
			return answer;
		}
	}
}