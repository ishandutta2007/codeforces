namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : Int
    {
        mutable ans = 0;
        CX(qs[0], qs[1]);
        if (M(qs[1]) == One){
            set ans += 2;
        }
        H(qs[0]);
        if (M(qs[0]) == One){
            set ans += 1;
        }
        return ans;
    }
}