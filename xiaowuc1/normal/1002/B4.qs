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

    operation Solve (qs : Qubit[]) : Int
    {
        body
        {
            H(qs[1]);
            CNOT(qs[0], qs[1]);
            H(qs[0]);
            let ans1 = M(qs[0]);
            mutable ret = 0;
            if(ans1 == Zero) {
                set ret = ret + 1;
            }
            let ans2 = Measure([PauliZ], [qs[1]]);
            // Message($"{ans1} {ans2}");
            if(ans2 == Zero) {
                set ret = ret + 2;
            }
            return ret;
        }
    }
}