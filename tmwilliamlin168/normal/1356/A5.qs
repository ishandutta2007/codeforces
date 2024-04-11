namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Measurement;
    open Microsoft.Quantum.Canon;
 
    operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        mutable res=0;
        using(q=Qubit[2]) {
            ApplyToEach(H, q);
            Controlled unitary(q[0..0], q[1]);
            H(q[0]);
            mutable h0=false;
            mutable h1=false;
            for(i in 0..1) {
                if(MResetZ(q[i])==One) {
                set h1=true;
                } else {
                set h0=true;
                }
            }
            if(h0&&h1) {
                set res=1;
            }
        }
        return res;
    }
}