namespace Solution {
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Extensions.Diagnostics;

    operation DM() : () {
        body {
            DumpMachine("/dev/stdout");
        }
    }

    operation Solve (q: Qubit, sign: Int) : () {
        body {
            if sign==1 { H(q); }
            if sign==-1 { X(q); H(q); }
        }
    }



    operation Tester() : () {
        body {
            let A=Solve;
            using(qbs=Qubit[1]) {
                let qb=qbs[0];
                A(qb, 0);
                DM();
                Message("stss2");
                Reset(qb);
                A(qb, 1);
                DM();
                Reset(qb);
            }
        }
    }
}