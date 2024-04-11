namespace Solution
{
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[], bits0 : Bool[], bits1 : Bool[]) : ()
    {
        body
        {
            mutable a=0;
            mutable b=false;
            for(i in 0..Length(qs)-1)
            {
                if(bits0[i]!=bits1[i])
                {
                    set a=i;
                    set b=bits0[i];
                }
            }
            H(qs[a]);
            for(i in 0..Length(qs)-1)
            {
                if(i!=a)
                {
                    if(bits0[i]!=bits1[i])
                    {
                        if(bits0[i]!=b)
                        {
                            X(qs[i]);
                        }
                        CNOT(qs[a], qs[i]);
                    }
                    elif(bits0[i])
                    {
                        X(qs[i]);
                    }
                }
            }
        }
    }
}