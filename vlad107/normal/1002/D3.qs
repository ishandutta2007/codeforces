namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (x : Qubit[], y : Qubit) : ()
    {
        body
        {
            for (i in 0..2)
            {
                for (j in i + 1..2)
                {
                    CCNOT(x[i], x[j], y);
                }
            }
        }
    }
}