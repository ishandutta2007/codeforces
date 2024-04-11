namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : Int
    {
        body
        {
            mutable result = 0;
            H(qs[0]);
            H(qs[1]);
            if (M(qs[0]) == Zero)
            {
                if (M(qs[1]) == Zero)
                {
                    set result = 0;
                } else 
                {
                    set result = 1;
                }
            } else 
            {
                if (M(qs[1]) == Zero)
                {
                    set result = 2;
                } else 
                {
                    set result = 3;
                }
            }
            return result;
        }
    }
}