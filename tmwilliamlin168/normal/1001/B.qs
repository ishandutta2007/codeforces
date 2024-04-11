namespace Solution
{
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[], index : Int) : ()
    {
        body
        {
            if(index==1||index==3)
            {
                X(qs[1]);
            }
            H(qs[1]);
            if(index==2||index==3)
            {
                X(qs[0]);
            }
            CNOT(qs[1], qs[0]);
        }
    }
}