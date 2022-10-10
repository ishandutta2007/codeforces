namespace Solution {
	open Microsoft.Quantum.Primitive;
	open Microsoft.Quantum.Canon;

	operation Solve (N : Int, Uf : ((Qubit[], Qubit) => ())) : Int[] {
		body {
			mutable b = new Int[N];
			using(res = Qubit[1]) {
				X(res[0]);
				H(res[0]);
				using(qs = Qubit[N]) {
					for(i in 0..N-1) {
						H(qs[i]);
					}
					Uf(qs, res[0]);
					for(i in 0..N-1) {
						H(qs[i]);
					}
					for(i in 0..N-1) {
						if(M(qs[i]) == One) {
							set b[i] = 1;
							X(qs[i]);
						}
						else {
							set b[i] = 0;
						}
					}
				}
				if(M(res[0]) == One) {
					X(res[0]);
				}
			}
			return b;
		}
	}
}