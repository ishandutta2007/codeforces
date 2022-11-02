namespace Solution
{
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Extensions.Bitwise;

    operation A (q: Qubit, sign: Int) : ()
    {
        body
        {
            if (sign == -1) {
                X(q);
            }
            H(q);
        }
    }

    operation Solve (qs : Qubit[], index : Int) : ()
    {
        body
        {
            if ((index == 1) || (index == 3)) 
            {
                X(qs[0]);
            }
            
            if ((index == 2) || (index == 3)) 
            {
                X(qs[1]);
            }

            H(qs[0]);
            CNOT(qs[0], qs[1]);
        }
    }
}