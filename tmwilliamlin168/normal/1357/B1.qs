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
        for(i in 0..Length(q)-1) {
            let j=Length(q)-1-i;
            Controlled X(q[0..j-1], q[j]);
        }
    }
 
    operation Solve (inputs : Qubit[], output : Qubit) : Unit is Adj+Ctl {
        let n=Length(inputs);
        if(n<=8) {
            using(q=Qubit[3]) {
                within {
                    for(q1 in inputs) {
                        Controlled inc([q1], q);
                    }
                } apply {
                    (ControlledOnInt(n/2, X))(q, output);
                }
            }
        } else {
            using(q=Qubit[2]) {
                within {
                    for(q1 in inputs) {
                        Controlled inc([q1], q);
                    }
                } apply {
                    (ControlledOnInt(1, X))(q, output);
                }
            }
            for(i in 0..9) {
                X(inputs[i]);
                Controlled X(inputs, output);
                ApplyToEachCA(X, inputs);
                Controlled X(inputs, output);
                ApplyToEachCA(X, inputs);
                X(inputs[i]);
            }
        }
    }
}