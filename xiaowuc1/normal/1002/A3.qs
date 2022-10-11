namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Set (desired: Result, q1: Qubit) : ()
    {
        body
        {
            let current = M(q1);
            if (desired != current)
            {
                X(q1);
            }
        }
    }

    operation Solve (qs : Qubit[], bits0 : Bool[], bits1 : Bool[]) : ()
    {
        body
        {
            mutable z = 0;
            for(k in 0..Length(qs)-1) {
                if(bits0[k] != bits1[k]) {
                    set z = k;
                }
            }
            H(qs[z]);
            for(i in 0..Length(qs)-1) {
                if(i == z) { }
                elif(bits0[i] && bits1[i]) {
                    X(qs[i]);
                }
                elif(bits0[i] == bits1[i]) { }
                elif(bits0[i] == bits0[z] && bits1[i] == bits1[z]) {
                    CNOT(qs[z], qs[i]);
                }
                else {
                    CNOT(qs[z], qs[i]);
                    X(qs[i]);
                }
            }
        }
    }
}