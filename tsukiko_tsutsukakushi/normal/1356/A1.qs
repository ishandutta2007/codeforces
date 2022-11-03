namespace Solution {
    open Microsoft.Quantum.Intrinsic;

    operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        // your code here
            using (qubit = Qubit()) {
                unitary(qubit);
                if(M(qubit) == Zero) {
                    Reset(qubit);
                    return 0;
                } else {
                    Reset(qubit);
                    return 1;
                }
            }
        
    }
}