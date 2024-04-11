namespace Solution {
    open Microsoft.Quantum.Arithmetic;
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Math;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Diagnostics;
    open Microsoft.Quantum.Convert;

    operation Solve (inputs : Qubit[], output : Qubit) : Unit is Adj+Ctl {
        let n=Length(inputs);
        using(o=Qubit[n]) {
            X(o[0]);
            for(i in 0..n-1) {
                for(j in 0..n-2) {
                    (Controlled SWAP)([inputs[i]],(o[j],o[j+1]));
                }
            }
            CNOT(o[n/2],output);
            for(i in 0..n-1) {
                for(j in 0..n-2) {
                    (Controlled SWAP)([inputs[i]],(o[n-1-j],o[n-2-j]));
                }
            }
            X(o[0]);
        }
    }
}