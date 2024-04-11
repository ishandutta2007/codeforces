namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Math;
    open Microsoft.Quantum.Diagnostics;
    
    operation Solve (unitary : ((Double, Qubit) => Unit is Adj+Ctl)) : Int {
        mutable ans = 0;
        using (q = Qubit[2]) {
            H(q[0]);
            CNOT(q[0], q[1]);
            Controlled unitary(q[1..1], (2.0 * PI(), q[0]));
            CNOT(q[0], q[1]);
            H(q[0]);
            if (M(q[0]) == Zero) {
                set ans = 1;
            }
            ResetAll(q);
        }
        return ans;
    }
}