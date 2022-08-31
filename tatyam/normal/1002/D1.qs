namespace Solution {
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Intrinsic;

    operation Solve (x : Qubit[], y : Qubit, b : Int[]) : Unit {
        let N = Length(b);
        for (i in 0 .. N - 1) {
            if (b[i] == 1) {
                CX(x[i], y);
            } 
        }
    }
}