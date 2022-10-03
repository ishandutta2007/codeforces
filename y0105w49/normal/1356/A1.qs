namespace Solution {

    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Intrinsic;

    operation Solve(unitary: (Qubit => Unit is Adj+Ctl)) : Int {
        body(...) {
            using(q=Qubit()) {
                Reset(q);
                unitary(q);
                mutable z=0;
                if (M(q)==One) {
                    X(q);
                    return 1;
                } else {
                    return 0;
                }
            }
        }
    }

    // @EntryPoint()
    operation Tester() : Unit {
        body(...) {
            Message("Hello quantum world!");
            for(i in 1..10) {
                Message($"{Solve(I)} - {Solve(X)}");
            }
        }
    }
}