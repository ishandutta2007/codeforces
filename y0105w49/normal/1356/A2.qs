namespace Solution {

    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Intrinsic;

    operation Solve(unitary: (Qubit => Unit is Adj+Ctl)) : Int {
        body(...) {
            using(q=Qubit()) {
                Reset(q);
                H(q);
                unitary(q);
                H(q);
                if (M(q)==One) {
                    X(q);
                    return 1;
                } else {
                    return 0;
                }
            }
        }
    }

    operation Tester() : Unit {
        body(...) {
            Message("Hello quantum world!");
            for(i in 1..10) {
                Message($"{Solve(I)} - {Solve(Z)}");
            }
        }
    }

    operation Main() : Unit {
        body(...) {
            Tester();
        }
    }
}