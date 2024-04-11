namespace Solution {
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Intrinsic;

    operation Solve (q : Qubit) : Int {
        if (Random([0.5, 0.5]) == 1) {
            if (M(q) == One) {
                return 1;
            }
            return -1;
        }
        else {
            H(q);
            if (M(q) == One) {
                return 0;
            }
            return -1;
        }
    }
}