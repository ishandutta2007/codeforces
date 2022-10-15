namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : ()
    {
        body
        {
            // your code here
            for (i in 0 .. Length(qs)-1)
            {
                H(qs[i]);
            }
        }
    }
}