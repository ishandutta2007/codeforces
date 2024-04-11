namespace Solution {
	open Microsoft.Quantum.Primitive;
	open Microsoft.Quantum.Canon;

	operation Solve (qs : Qubit[]) : () {
		body {
			let N = Length(qs);
			if(N == 1) {
				X(qs[0]);
				return ();
			}
			let mid = N/2;
			let lft = qs[0..mid-1];
			Solve(lft);
			H(qs[mid]);
			for(i in mid+1..N-1) {
				(Controlled SWAP)([qs[mid]], (qs[i], qs[i-mid]));
			}
			for(i in mid..N-1) {
				CNOT(qs[i], qs[0]);
			}
			for(i in mid+1..N-1) {
				CNOT(qs[i], qs[mid]);
			}
		}
	}
}