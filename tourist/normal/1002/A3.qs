namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[], bits0 : Bool[], bits1 : Bool[]) : ()
    {
        body
        {
			mutable first = -1;
			for (i in 0..Length(qs)-1) {
			    if (bits0[i] != bits1[i]) {
				    if (first == -1) {
						H(qs[i]);
						set first = i;
					} else {
					    CNOT(qs[first], qs[i]);
					}
				}
			}            
			for (i in 0..Length(qs)-1) {
			    if (bits0[i]) {
				    X(qs[i]);
			    }
		    }
        }
    }
}