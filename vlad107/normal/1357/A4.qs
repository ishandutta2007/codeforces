namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Math;

    operation Solve (unitary : ((Double, Qubit) => Unit is Adj+Ctl)) : Int {
        mutable result = 0;
        using (qs = Qubit[2]) {
            H(qs[0]);
            X(qs[1]);
            Controlled unitary(qs[0..0], (PI() * 2., qs[1]));
            H(qs[0]);
            let r = M(qs[0]);
            if (r == One) {
                set result = 0;
            } else {
                set result = 1;
            }
            ResetAll(qs);
        }
        return result;
    }
}