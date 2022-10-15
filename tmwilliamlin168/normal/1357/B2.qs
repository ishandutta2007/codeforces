namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Measurement;
    open Microsoft.Quantum.Math;
    open Microsoft.Quantum.Convert;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Arithmetic;
    open Microsoft.Quantum.Diagnostics;
    open Microsoft.Quantum.Arrays;
    
    operation inc(q : Qubit[]) : Unit is Adj+Ctl {
        CNOT(q[0], q[1]);
        CNOT(q[1], q[0]);
    }
 
    operation Solve (inputs : Qubit[], output : Qubit) : Unit is Adj+Ctl {
        let n=Length(inputs);
        using(q=Qubit[2]) {
            within {
                X(q[0]);
                X(q[1]);
                if(0<n) {
                    Controlled inc([inputs[0]], q);
                }
                if(2<n) {
                    Controlled inc([inputs[2]], q);
                }
                if(4<n) {
                    Controlled inc([inputs[4]], q);
                }
                if(6<n) {
                    Controlled inc([inputs[6]], q);
                }
                if(1<n) {
                    Controlled Adjoint inc([inputs[1]], q);
                }
                if(3<n) {
                    Controlled Adjoint inc([inputs[3]], q);
                }
                if(5<n) {
                    Controlled Adjoint inc([inputs[5]], q);
                }
                if(7<n) {
                    Controlled Adjoint inc([inputs[7]], q);
                }
            } apply {
                Controlled X(q, output);
            }
        }
    }
}