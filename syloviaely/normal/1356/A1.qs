namespace Solution {
    open Microsoft.Quantum.Intrinsic;

    operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
    	using (q=Qubit()) {
    		unitary(q);
    		let ans = M(q);
    		Reset(q);
    		if (ans == Zero) {return 0;} else {return 1;}
    	}
    }
}