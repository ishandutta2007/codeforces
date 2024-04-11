namespace Solution {
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Extensions.Diagnostics;

    operation DM() : () {
        body {
            DumpMachine("/dev/stdout");
        }
    }

    operation Solve (qs: Qubit[], idx: Int) : () {
        body {
            H(qs[0]);
            CNOT(qs[0],qs[1]);
            if((idx&&&1)!=0) {Z(qs[1]);}
            if((idx&&&2)!=0) {X(qs[1]);}
        }
    }



    operation Tester() : () {
        body {
            using(qs=Qubit[2]) {
                for (k in 0..3) {
                    Solve(qs,k);
                    DM();
                    ResetAll(qs);
                }
            }
        }
    }
}