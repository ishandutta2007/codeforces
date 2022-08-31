namespace Solution {
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Math;

    operation Solve (q : Qubit) : Int {
        Ry(PI() / 4.0, q);
        if (M(q) == One) {
            return 1;
        }
        return 0;
    }
}