namespace Solution
{
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Op1 (q1 : Qubit, q2 : Qubit) : ()
    {
        body
        {
            // X(q2);
            // H(q1);
            // CNOT(q1, q2);
            // CNOT(q1, q2);
            // H(q1);
            // T(q1);
            // H(q1);
            // (Adjoint T)(q2);
            // H(q2);
            // CNOT(q1, q2);
            // H(q1);
            // H(q2);
            // (Adjoint T)(q1);
            // H(q1);
            // CNOT(q1, q2);
            // (Adjoint T)(q1);
            // (Adjoint T)(q2);
            (Controlled H)([q1], q2);
            CNOT(q2, q1);
        }
    }

    operation Op2 (qs : Qubit[], i : Int, j : Int, k : Int) : ()
    {
        body
        {
            if(k>0)
            {
                Op1(qs[i], qs[i+j]);
                Op2(qs, i, j/2, k-1);
                Op2(qs, i+j, j/2, k-1);
            }
        }
    }

    operation Solve (qs : Qubit[]) : ()
    {
        body
        {
            mutable x=1;
            mutable y=-1;
            repeat
            {
                set x=x*2;
                set y=y+1;
            }
            until(x>Length(qs))
            fixup {};
            X(qs[0]);
            Op2(qs, 0, Length(qs)/2, y);
        }
    }
}