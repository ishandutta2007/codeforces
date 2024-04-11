namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Diagnostics;
 
    operation Solve (qs : Qubit[]) : Unit {
        mutable succeed=false;
        let s=Length(qs);
        repeat {
            for(i in 0..s-1) {
                H(qs[i]);
            }
            using(w=Qubit()) {
                (Controlled X)(qs,w);
                if(M(w)==One) {X(w);}
                else {
                    set succeed=true;
                }
            }
        }
        until (succeed)
        fixup {
            ResetAll(qs);
        }
    }
}