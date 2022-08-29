namespace Solution {
    open Microsoft.Quantum.Arrays;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Diagnostics;
    open Microsoft.Quantum.Intrinsic;

    operation Solve (N : Int, Uf : ((Qubit[], Qubit) => Unit)) : Int[] {
        mutable ans = new Int[N];
        using ((x, y) = (Qubit[N], Qubit())) {
            ApplyToEach(X, x);
            Uf(x, y);
            if (M(y) == One) {
                set ans w/= 0 <- 1;
            }
            ResetAll(x + [y]);
        }
        return ans;
    }
}