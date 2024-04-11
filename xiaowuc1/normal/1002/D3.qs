namespace Solution {
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Extensions.Diagnostics;

    operation DM() : () {
        body {
            DumpMachine("/dev/stdout");
        }
    }

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

    operation Toffoli (q1: Qubit, q2: Qubit, ret: Qubit) : ()
    {
        body
        {
            H(ret);
            CNOT(q2, ret);
            (Adjoint T)(ret);
            CNOT(q1, ret);
            T(ret);
            CNOT(q2, ret);
            (Adjoint T)(ret);
            CNOT(q1, ret);
            (Adjoint T)(q2);
            T(ret);
            CNOT(q1, q2);
            H(ret);
            (Adjoint T)(q2);
            CNOT(q1, q2);
            T(q1);
            S(q2);
            
        }
    }

    operation Solve (x : Qubit[], y : Qubit) : ()
    {
        body
        {
           Toffoli(x[0], x[1], y);
           Toffoli(x[0], x[2], y);
           Toffoli(x[1], x[2], y);
        }
    }

    operation Test() : () {
        body {
            
        }
    }
}