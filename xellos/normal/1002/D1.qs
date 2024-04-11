namespace Solution {
	open Microsoft.Quantum.Primitive;
	open Microsoft.Quantum.Canon;

	operation Solve (x : Qubit[], y : Qubit, b : Int[]) : () {
		body {
			let N = Length(b);
			for(i in 0..N-1) {
				if(b[i] == 1) {
					CNOT(x[i], y);
				}
			}
		}
	}
}