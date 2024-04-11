namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Measurement;
    open Microsoft.Quantum.Math;
    open Microsoft.Quantum.Convert;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Arithmetic;
    open Microsoft.Quantum.Diagnostics;
    open Microsoft.Quantum.Arrays;
 
    operation Solve (qs : Qubit[], parity : Int) : Unit {
        ApplyToEach(H, Most(qs));
        for(q in Most(qs)) {
            CNOT(q, qs[Length(qs)-1]);
        }
        if(parity==1) {
            X(qs[0]);
        }
    }
}