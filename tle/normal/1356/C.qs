namespace Solution {
    open Microsoft.Quantum.Intrinsic;

    operation Solve (qs : Qubit[]) : Unit {
        mutable succeed=false;
        repeat {
            H(qs[0]);
            H(qs[1]);
            using(w=Qubit()) {
                (Controlled X)(qs,w);
                if(M(w)==One) {X(w);}
                else {X(qs[0]); X(qs[1]); set succeed=true;}
            }
        }
        until (succeed)
        fixup {
            if(M(qs[0])==One) {X(qs[0]);}
            if(M(qs[1])==One) {X(qs[1]);}
        }
    }
}