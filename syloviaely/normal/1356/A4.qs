namespace Solution {
    open Microsoft.Quantum.Intrinsic;

    operation Solve (unitary : (Qubit[] => Unit is Adj+Ctl)) : Int {
    	using (q1=Qubit()) {
    		using (q2=Qubit()) {
    			unitary([q1, q2]);
    			let res1 = M(q1);
    			let res2 = M(q2);
    			Reset(q1);
    			Reset(q2);
    			if (res1 == res2) {return 1;} else {return 0;}
    		}
    	}
    }
}