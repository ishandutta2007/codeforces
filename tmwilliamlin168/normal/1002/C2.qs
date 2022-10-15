namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (q : Qubit) : Int
    {
        body
        {
            if(Random([0.5; 0.5])==0)
            {
                if(M(q)==One)
                {
                    return 1;
                }
                else
                {
                    return -1;
                }
            }
            else
            {
                H(q);
                if(M(q)==One)
                {
                    return 0;
                }
                else
                {
                    return -1;
                }
            }
        }
    }
}