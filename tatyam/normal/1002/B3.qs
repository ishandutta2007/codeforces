namespace Solution {
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Intrinsic;

    operation Solve (qs : Qubit[]) : Int {
        H(qs[0]);
        H(qs[1]);
        mutable ans = 0;
        if (M(qs[0]) == One) {
            set ans += 2;
        }
        if (M(qs[1]) == One) {
            set ans += 1;
        }
        return ans;
    }
}