namespace Solution {
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Extensions.Diagnostics;

    operation DM() : () {
        body {
            DumpMachine("/dev/stdout");
        }
    }

    operation Solve (q: Qubit) : Int {
        body {
            H(q);
            let z=M(q);
            if(z==Zero) { return 1; }
            return -1;
        }
    }



    operation Tester() : () {
        body {
            using(qs=Qubit[1]) {
                let q=qs[0];
                H(q);
                let a=Solve(q);
                Message($"{a}");
                DM();
                ResetAll(qs);
                X(q); H(q);
                let b=Solve(q);
                Message($"{b}");
                DM();
                ResetAll(qs);
            }
        }
    }
}