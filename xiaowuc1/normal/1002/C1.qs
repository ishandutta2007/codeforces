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

    operation Solve (q : Qubit) : Int
    {
        body
        {
            Ry(0.7, q);
            if(M(q) == One) {
                return 1;
            }
            return 0;
        }
    }

    operation Test() : () {
        body {
            mutable ret = 0;
            for(k in 0..10000) {
                using(qs=Qubit[1]) {
                    // DM();
                    if(Solve(qs[0]) == 0) {
                        set ret = ret+1;
                    }
                    ResetAll(qs);
                    H(qs[0]);
                    // DM();
                    if(Solve(qs[0]) == 1) {
                        set ret = ret+1;
                    }
                    // Message($"{z}");
                    ResetAll(qs);
                }
            }
            Message($"{ret}");
        }
    }
}