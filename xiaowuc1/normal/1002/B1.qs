namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Set (desired: Result, q1: Qubit) : ()
    {
        body
        {
            let current = M(q1);
            if (desired != current)
            {
                X(q1);
            }
        }
    }

    operation Solve (qs : Qubit[]) : Int
    {
        body
        {
            for(i in 0..Length(qs)-1) {
                let ret = M(qs[i]);
                if(ret == One) {
                    return 1;
                }
            }
            return 0;
        }
    }
}