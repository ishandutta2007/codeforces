namespace Solution {
    open Microsoft.Quantum.Intrinsic;

    operation Solve (qs : Qubit[]) : Unit {
        using (q = Qubit()){
        	repeat {
        		Reset(q);
        		ResetAll(qs);
        		H(qs[0]);
        		H(qs[1]);
        		Controlled X(qs, q);
        	} until (M(q) == Zero);
        	X(qs[0]);
        	X(qs[1]);
        }
    }
}