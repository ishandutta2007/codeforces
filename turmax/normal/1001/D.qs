namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (q : Qubit) : Int
    {
        body
        {
            H(q);
            if(M(q)==Zero)
            {
            return 1;
            }
            else 
            {
            return -1;
            }
        }
    }
}