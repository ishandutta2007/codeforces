namespace Solution {
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Extensions.Diagnostics;

    operation DM() : () {
        body {
            DumpMachine("/dev/stdout");
        }
    }

    operation Solve (qs: Qubit[]) : () {
        body {
            H(qs[0]);
            for (i in 1..Length(qs)-1) {
                CNOT(qs[0],qs[i]);
            }
        }
    }



    operation Tester() : () {
        body {
            using(qs=Qubit[8]) {
                for (n in 1..8) {
                    Solve(qs[0..n-1]);
                    DM();
                    ResetAll(qs);
                }
            }
        }
    }
}