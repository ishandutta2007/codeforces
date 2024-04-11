namespace Solution {

    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Intrinsic;

    operation Solve(unitary: (Qubit[] => Unit is Adj+Ctl)) : Int {
        body(...) {
            using(qs=Qubit[2]) {
                unitary(qs);
                if (M(qs[1])==One) {
                    X(qs[1]);
                    return 0;
                } else {
                    return 1;
                }
            }
        }
    }

    operation Tester() : Unit {
        body(...) {
            Message("Hello quantum world!");
            for(i in 1..10) {
                Message($"{Solve(ApplyPauli([PauliI,PauliX],_))} - {Solve(ApplyToFirstTwoQubitsCA(CNOT,_))}");
            }
        }
    }

    operation Main() : Unit {
        body(...) {
            Tester();
        }
    }
}