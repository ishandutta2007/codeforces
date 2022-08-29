namespace Solution {
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Intrinsic;

    operation Solve (x : Qubit[], y : Qubit) : Unit {
        ApplyToEach(CX(_, y), x);
    }
}