namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[], b0 : Bool[], b1 : Bool[]) : Unit
    {
        body(...)
        {
            mutable B0=b0;
            mutable B1=b1;
            mutable g=0;
            for(i in 0..Length(qs)-1)
            {
                if(b0[i]!=b1[i])
                {
                    set g=i;
                }
            }
            if(b0[g])
            {
                set B0=b1;
                set B1=b0;
            }
            H(qs[g]);
            for(i in 0..Length(qs)-1)
            {
                if(i!=g)
                {
                    if(B0[i]==B1[i])
                    {
                        if(B0[i])
                        {
                            X(qs[i]);
                        }
                    }
                    else
                    {
                        if(B0[i])
                        {
                            X(qs[i]);
                        }
                        CNOT(qs[g],qs[i]);
                    }
                }
            }
        }
    }
}