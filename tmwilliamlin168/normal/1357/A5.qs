namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Measurement;
    open Microsoft.Quantum.Math;
    open Microsoft.Quantum.Convert;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Arithmetic;
    open Microsoft.Quantum.Diagnostics;
    open Microsoft.Quantum.Arrays;
 
    operation Solve (theta : Double, unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        mutable r=0;
        mutable t=1;
        repeat {}
        until(IntAsDouble(t+1)*theta>=PI())
        fixup {
        	set t+=1;
        }
        using (q=Qubit()) {
        for(it in 0..100/t) {
            for(i in 0..t-1) {
                unitary(q);
            }
            if(MResetZ(q)==One) {
            set r=1;
            }
        }
        }
        return r;
    }
}