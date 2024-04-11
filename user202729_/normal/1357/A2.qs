namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Measurement;
 
    operation Solve (unitary : (Qubit[] => Unit is Adj+Ctl)) : Int {
        mutable result=0;
        using(q=Qubit[2]){
            X(q[0]); X(q[1]);
            unitary(q);
            let a=MResetZ(q[0]);
            let b=MResetZ(q[1]);
            if(a==Zero){ return 2; }else{
            if(b==Zero){ return 1; }else{
            
            X(q[0]);
            unitary(q);
            let c=MResetZ(q[0]);
            Reset(q[1]);
            if(c==One){ return 0; } else{ return 3; }
            }
            }
        }
    }
}