namespace Solution {
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Intrinsic;
    
    operation Solve (qs : Qubit[], bits : Bool[]) : Unit {
        let N = Length(qs);
        H(qs[0]);
        for (i in 1 .. N - 1) {
            if (bits[i]) {
                CX(qs[0], qs[i]);
            }
        }
    }
}