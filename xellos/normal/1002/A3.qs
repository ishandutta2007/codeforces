namespace Solution {
	open Microsoft.Quantum.Primitive;
	open Microsoft.Quantum.Canon;

	operation Solve (qs : Qubit[], bits0 : Bool[], bits1 : Bool[]) : () {
		body {
			let N = Length(qs);
			mutable findex = -1;
			for(i in 0..N-1) {
				if(bits0[i] != bits1[i]) {
					if(findex == -1) {
						set findex = i;
						H(qs[i]);
					}
					else {
						CNOT(qs[findex], qs[i]);
					}
				}
			}
			for(i in 0..N-1) {
				if(bits0[i]) {
					X(qs[i]);
				}
			}
		}
	}
}