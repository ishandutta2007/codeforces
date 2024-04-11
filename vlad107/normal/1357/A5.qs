namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Math;

    operation Solve (theta : Double, unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        mutable r0 = 0;
        mutable r1 = 0;
        using (q = Qubit()) {
            let num = Round(PI() / theta);
            for (j in 0..15) {
                for (i in 0..num - 1) {
                    unitary(q);
                }
                let r = M(q);
                if (r == Zero) {
                    set r0 += 1;
                } else {
                    set r1 += 1;
                }
                Reset(q);
            }
        }
        return r0 > r1 ? 0 | 1;
    }
}