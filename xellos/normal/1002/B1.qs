namespace Solution {
	open Microsoft.Quantum.Primitive;
	open Microsoft.Quantum.Canon;

	operation Solve (qs : Qubit[]) : Int {
		body {
			let N = Length(qs);
			for(i in 0..N-1) {
				if(M(qs[i]) == One) {
					return 1;
				}
			}
			return 0;
		}
	}
}