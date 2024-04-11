namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Convert;
    open Microsoft.Quantum.Math;
    open Microsoft.Quantum.Diagnostics;
    
    operation Solve (theta : Double, unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        mutable k = 0;
        mutable rem = -PI();
        mutable minrem = PI();
        for (i in 1..100) {
            set rem += theta;
            if (rem > PI()){
                set rem -= PI() * 2.0;
            }
            if (minrem > AbsD(rem)) {
                set minrem = AbsD(rem);
                set k = i;
            }
        }
        mutable ans = 0;
        for (i in 1..3) {
            using (q = Qubit()) {
                for (j in 1..k) {
                    unitary(q);
                }
                if (M(q) == One) {
                    set ans += 1;
                }
                Reset(q);
            }
        }
        set ans = ans > 1 ? 1 | 0;
        return ans;
    }
}