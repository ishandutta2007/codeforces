namespace Solution {

    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Diagnostics;
    open Microsoft.Quantum.Intrinsic;

    operation Solve(unitary: (Qubit => Unit is Adj+Ctl)) : Int {
        body(...) {
            using(qs=Qubit[2]) {
                let q=qs[0];
                let r=qs[1];
                H(q);
                CNOT(q,r);
                (Controlled unitary)([q],r);
                CZ(q,r);
                CNOT(q,r);
                H(q);
                if (M(q)==One) {
                    ResetAll(qs);
                    return 1;
                } else {
                    ResetAll(qs);
                    return 0;
                }
            }
        }
    }

    operation mZ(q: Qubit) : Unit is Adj+Ctl {
        body(...) {
            X(q);
            Z(q);
            X(q);
        }
    }
    operation Tester() : Unit {
        body(...) {
            Message("Hello quantum world!");
            for(i in 1..1) {
                // Message($"{Solve(ApplyPauli([PauliI,PauliX],_))} - {Solve(ApplyToFirstTwoQubitsCA(CNOT,_))}");
                Message($"{Solve(Z)} - {Solve(mZ)}");
            }
        }
    }

    operation Main() : Unit {
        body(...) {
            Tester();
        }
    }
}