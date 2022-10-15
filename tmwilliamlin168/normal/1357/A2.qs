namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Measurement;
 
    operation Solve (unitary : (Qubit[] => Unit is Adj+Ctl)) : Int {
        // your code here
        mutable r=0;
        using(q=Qubit[2]) {
            X(q[0]);
            unitary(q);
            let a=MResetZ(q[0]);
            let b=MResetZ(q[1]);
            if(a==Zero&&b==One) {
            set r=3;
            } elif(a==One&&b==One) {
            set r=1;
            } else {
                X(q[1]);
                unitary(q);
                let c=MResetZ(q[0]);
                let d=MResetZ(q[1]);
                if(c==One) {
                set r=2;
                }
            }
        }
        return r;
    }
}