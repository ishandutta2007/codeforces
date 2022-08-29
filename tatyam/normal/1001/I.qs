namespace Solution {
    open Microsoft.Quantum.Arithmetic;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Intrinsic;
    
    operation Solve (N : Int, Uf : ((Qubit[], Qubit) => Unit)) : Bool {
        mutable ans = false;
        using ((x, y) = (Qubit[N], Qubit())) {
            X(y);
            ApplyToEach(H, x);
            H(y);
            Uf(x, y);
            ApplyToEach(H, x);
            let lx = LittleEndian(x);
            set ans = MeasureInteger(lx) == 0;
            ResetAll(x);
            Reset(y);
        }
        return ans;
    }
}