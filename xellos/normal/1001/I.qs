namespace Solution {
	open Microsoft.Quantum.Primitive;
	open Microsoft.Quantum.Canon;

	operation Solve (N : Int, Uf : ((Qubit[], Qubit) => ())) : Bool {
		body {
			mutable result = true;
			using(res = Qubit[1]) {
				H(res[0]);
				Z(res[0]);
				using(qs = Qubit[N]) {
					for(i in 0..N-1) {
						H(qs[i]);
					}
					Uf(qs, res[0]);
					for(i in 0..N-1) {
						if(Measure([PauliX], [qs[i]]) == One) {
							set result = false;
							Z(qs[i]);
						}
						H(qs[i]);
					}
				}
				Reset(res[0]);
			}
			return result;
		}
	}
}