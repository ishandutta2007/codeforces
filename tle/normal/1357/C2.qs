namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Diagnostics;
    open Microsoft.Quantum.Convert;
 
    operation Solve (qs : Qubit[], parity : Int) : Unit {
        mutable succeed=false;
        let s=Length(qs);
        repeat {
            for(i in 0..s-1) {
                H(qs[i]);
            }
            using(w=Qubit()) {
                for(i in 0..s-1) {
                    CNOT(qs[i],w);
                }
                let res=M(w);
                if((res==One and parity==1) or (res==Zero and parity==0)) {
                    set succeed=true;
                }
                Reset(w);
            }
        }
        until (succeed)
        fixup {
            ResetAll(qs);
        }
    }
}