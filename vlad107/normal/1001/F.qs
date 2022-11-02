namespace Solution
{
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Extensions.Bitwise;

    operation Solve (qs : Qubit[], bits0 : Bool[], bits1 : Bool[]) : Int
    {
        body
        {
            for (i in 0..Length(qs) - 1)
            {
                let val = (M(qs[i]) == One);
                if (val != bits0[i]) 
                {
                    return 1;
                }
            }
            return 0;
        }
    }
}