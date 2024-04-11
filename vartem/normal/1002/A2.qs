namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[], bits : Bool[]) : ()
    {
        body
        {
            mutable pos = -1;
            H(qs[0]);
            for (i in 1..Length(qs) - 1) {
                if (bits[i] != false) {
                    CNOT(qs[0], qs[i]);
                }
            }
        }
    }
}