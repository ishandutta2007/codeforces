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
            H(qs[0]);
            H(qs[1]);
            let ans1 = M(qs[0]);
            mutable ret = 0;
            if(ans1 == One) {
                set ret = ret + 2;
            }
            let ans2 = Measure([PauliZ], [qs[1]]);
            // Message($"{ans1} {ans2}");
            if(ans2 == One) {
                set ret = ret + 1;
            }
            return ret;
        }
    }

    operation Test() : () {
        body {
            for(k in 0..10) {
                using(qs=Qubit[2]) {
                    H(qs[0]);
                    Z(qs[0]);
                    H(qs[1]);
                    Z(qs[1]);
                    let z=Solve(qs);
                    Message($"{z}");
                    ResetAll(qs);
                }
            }
        }
    }
}