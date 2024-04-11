namespace Solution {
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Intrinsic;

    operation Solve (qs : Qubit[]) : Int {
        let N = Length(qs);
        mutable cnt = 0;
        for (q in qs) {
            if(M(q) == One) {
                set cnt += 1;
            }
        }
        if (cnt != 1) {
            return 0;
        }
        return 1;
    }
}