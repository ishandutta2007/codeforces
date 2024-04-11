namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[], bits0 : Bool[], bits1 : Bool[]) : ()
    {
        body
        {
            mutable pos = -1;
            for (i in 0..Length(qs) - 1) {
                if (bits0[i] != bits1[i]) {
                    if (pos == -1) {
                        set pos = i;
                        H(qs[pos]);
                    } else {
                        CNOT(qs[pos], qs[i]);
                    }
                }
            }
            for (i in 0..Length(qs) - 1) {
                if (bits0[i] == true) {
                    X(qs[i]);
                }
            }
        }
    }
}