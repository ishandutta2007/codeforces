namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[], bits : Bool[][]) : Unit {
    	using (ex = Qubit[2]) {
    		H(ex[0]);
    		H(ex[1]);
    		for (i in 0 .. 3) {
    			for (j in 0 .. Length(qs) - 1) {
    				if (bits[i][j]) {
    					(ControlledOnInt(i, X))(ex, qs[j]);
    				}
    			}
    		}
    		for (i in 0 .. 3) {
    			if (i % 2 == 1) {
    				(ControlledOnBitString(bits[i], X))(qs, ex[0]);
    			}
    			if (i / 2 == 1) {
    				(ControlledOnBitString(bits[i], X))(qs, ex[1]);
    			}
    		}
    	}
    }
}