namespace Solution
{
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : Int
    {
        body
        {
            CNOT(qs[0], qs[1]);
            mutable res=0;
            if(M(qs[1])==One)
            {
                set res=res+2;
            }
            H(qs[0]);
            if(M(qs[0])==One)
            {
                set res=res+1;
            }
            return res;
        }
    }
}