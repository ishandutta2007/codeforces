namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[], bits : Bool[]) : ()
    {
        body
        {
            mutable a=0;
            for (i in 0 .. Length(qs)-1)
            {
                if(bits[i])
                {
                    set a=i;
                }
            }
            H(qs[a]);
            for (i in 0 .. Length(qs)-1)
            {
                if(bits[i]&&i!=a)
                {
                    CNOT(qs[a], qs[i]);
                }
            }
        }
    }
}