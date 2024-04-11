namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : Int
    {
        body
        {
            mutable x=2;
            for(i in 0..Length(qs)-1)
            {
                if(M(qs[i])==One)
                {
                    if(x!=2&&x!=1)
                    {
                        return 1;
                    }
                    set x=1;
                }
                else
                {
                    if(x!=2&&x!=0)
                    {
                        return 1;
                    }
                    set x=0;
                }
            }
            return 0;
        }
    }
}