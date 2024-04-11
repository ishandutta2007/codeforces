namespace Solution {
    open Microsoft.Quantum.Intrinsic;

    operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
    	using (q1=Qubit()) {
    		using (q2=Qubit()) {
    			H(q1);
    			Controlled X([q1], q2);
    			Controlled unitary([q1], q2);
    			H(q1);
    			H(q2);
    			let res1 = M(q1);
    			let res2 = M(q2);
    			Reset(q1);
    			Reset(q2);
    			if (res1 == res2) {return 0;} else {return 1;}
    		}
    	}
    }
}