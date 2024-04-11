namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[], bits : Bool[]) : ()
    {
        body
        {
			mutable first = -1;
			for (i in 0..Length(qs)-1) {
			    if (bits[i]) {
				    if (first == -1) {
						H(qs[i]);
						set first = i;
					} else {
					    CNOT(qs[first], qs[i]);
					}
				}
			}            
        }
    }
}