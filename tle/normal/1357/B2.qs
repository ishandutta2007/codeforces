namespace Solution {
    open Microsoft.Quantum.Arithmetic;
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Math;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Diagnostics;
    open Microsoft.Quantum.Convert;

    operation Solve (inputs : Qubit[], output : Qubit) : Unit is Adj+Ctl {
        using(o=Qubit[3]) {
            X(o[0]);
            for(i in 0..2..Length(inputs)-1) {
                (Controlled SWAP)([inputs[i]],(o[0],o[1]));
                (Controlled SWAP)([inputs[i]],(o[1],o[2]));
            }
            for(i in 1..2..Length(inputs)-1) {
                (Controlled SWAP)([inputs[i]],(o[0],o[2]));
                (Controlled SWAP)([inputs[i]],(o[1],o[2]));
            }
            CNOT(o[0],output);
            for(i in 1..2..Length(inputs)-1) {
                (Controlled SWAP)([inputs[i]],(o[0],o[1]));
                (Controlled SWAP)([inputs[i]],(o[1],o[2]));
            }
            for(i in 0..2..Length(inputs)-1) {
                (Controlled SWAP)([inputs[i]],(o[0],o[2]));
                (Controlled SWAP)([inputs[i]],(o[1],o[2]));
            }
            X(o[0]);
        }
    }
}