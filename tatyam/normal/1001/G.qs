namespace Solution {
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Intrinsic;
    
    operation Solve (x : Qubit[], y : Qubit, k : Int) : Unit
    {
        CX(x[k], y);
    }
}