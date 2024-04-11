namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[], bits0 : Bool[], bits1 : Bool[]) : ()
    {
        body
        {
            mutable diffIndex = 0;
            for (i in 0..Length(qs) - 1)
            {
                if (bits0[i] != bits1[i])
                {
                    set diffIndex = i;
                }
            }
            H(qs[diffIndex]);
            if (bits0[diffIndex] == true)
            {
                X(qs[diffIndex]);
            }
            for (i in 0..Length(qs) - 1)
            {
                if (bits0[i] == bits1[i])
                {
                    if (bits0[i] == true)
                    {
                        X(qs[i]);
                    }
                } else {
                    if (diffIndex != i)
                    {
                        CNOT(qs[diffIndex], qs[i]);
                        if (bits0[i] != bits0[diffIndex])
                        {
                            X(qs[i]);
                        }
                    }
                }
            }
        }
    }
}