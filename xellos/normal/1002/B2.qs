namespace Solution {
	open Microsoft.Quantum.Primitive;
	open Microsoft.Quantum.Canon;

	operation Solve (qs : Qubit[]) : Int {
		body {
			let N = Length(qs);
			mutable has0 = false;
			mutable has1 = false;
			for(i in 0..N-1) {
				if(M(qs[i]) == One) {
					set has1 = true;
				}
				else {
					set has0 = true;
				}
			}
			if(has0 && has1) {
				return 1;
			}
			return 0;
		}
	}
}