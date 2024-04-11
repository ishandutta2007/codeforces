namespace Solution {
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Extensions.Diagnostics;
    open Microsoft.Quantum.Extensions.Testing;

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
            // when rotate y, plus sign always has pauliX one
            // when rotate y, zero can have pauliX zero
            mutable ans = -1;
            using(rr=Qubit[1]) {
                H(rr[0]);
                if(M(rr[0]) == One) {
                    if(M(q) == One) {
                        set ans = 1;
                    }
                }
                else {
                    if(Measure([PauliX], [q]) == One) {
                        set ans = 0;
                    }
                }
                ResetAll(rr);
            }
            return ans;
        }
    }

    operation Test() : () {
        body {
            for(k in 0..100) {
                using(qs=Qubit[1]) {
                    // H(qs[0]);
                    let ret = Solve(qs[0]);
                    Message($"{ret}");
                    ResetAll(qs);
                }
            }
        }
    }
}