namespace Solution {
    open Microsoft.Quantum.Intrinsic;

    operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        mutable ans = 0;
        using (q0 = Qubit()) {
            H(q0);
            using (q1 = Qubit()) {
                CNOT(q0, q1);
                Controlled unitary([q1], q0);
                CNOT(q0, q1);
            }
            H(q0);
            if(M(q0) == Zero){
                set ans = 1;
            }
            Reset(q0);
        }
        return ans;
    }
}