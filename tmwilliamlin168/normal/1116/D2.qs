namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : Unit {
        for(q in qs) {
            X(q);
        }
        for(i in 0..Length(qs)-1) {
            X(qs[i]);
            H(qs[i]);
            Controlled H(qs[i+1..Length(qs)-1], qs[i]);
        }
    }
}