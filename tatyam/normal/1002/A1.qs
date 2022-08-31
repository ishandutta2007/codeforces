namespace Solution {
    open Microsoft.Quantum.Arithmetic;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Intrinsic;
    
    operation Solve (qs : Qubit[]) : Unit {
        ApplyToEach(H, qs);
    }
}