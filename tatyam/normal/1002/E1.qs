namespace Solution {
    open Microsoft.Quantum.Arrays;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Intrinsic;

    operation MResetZ(q : Qubit) : Int {
        let res = M(q);
        Reset(q);
        if (res == One) {
            return 1;
        }
        else {
            return 0;
        }
    }

    operation Solve (N : Int, Uf : ((Qubit[], Qubit) => Unit)) : Int[] {
        using ((x, y) = (Qubit[N], Qubit())) {
            X(y);
            ApplyToEach(H, x + [y]);
            Uf(x, y);
            ApplyToEach(H, x);
            let ans = ForEach(MResetZ, x);
            Reset(y);
            return ans;
        }
    }
}