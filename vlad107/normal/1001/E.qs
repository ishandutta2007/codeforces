namespace Solution
{
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Extensions.Bitwise;

    operation Solve (qs : Qubit[]) : (Int)
    {
        body
        {
            CNOT(qs[0], qs[1]);
            H(qs[0]);
            mutable index = 0;
            if (M(qs[0]) == One)
            {
                set index = index + 1;
            }
            
            if (M(qs[1]) == One) 
            {
                set index = index + 2;
            }
            return index;
        }
    }
}