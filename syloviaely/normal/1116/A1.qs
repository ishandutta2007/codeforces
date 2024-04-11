namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : Unit {
    	using (q = Qubit()) {
	        repeat{
	        	Reset(q);
	        	ResetAll(qs);
	        	H(qs[0]);
	        	H(qs[1]);
	        	Controlled X(qs, q);
	        }until(M(q) == Zero);
	        Reset(q);
        }
    }
}