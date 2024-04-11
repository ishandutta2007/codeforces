namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : Int
    {
        body
        {
            mutable result = 0;
            revGHZ(qs);
            for (i in 0..Length(qs) - 1)
            {
                if (M(qs[i]) == One)
                {
                    set result = 1;
                }
            }
            return result;
        }
    }

    operation revGHZ (qs : Qubit[]) : ()
    {
        body
        {
            for (i in 1..Length(qs) - 1)
            {
                CNOT(qs[0], qs[i]);
            }
            H(qs[0]);
        }
    }
}