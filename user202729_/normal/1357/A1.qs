namespace Solution {
    open Microsoft.Quantum.Intrinsic;

    operation Solve (unitary : (Qubit[] => Unit is Adj+Ctl)) : Int {
        mutable result=0;
        using(q=Qubit[2]){
            X(q[0]);
            unitary(q);
            if(M(q[1])==One){
                set result=0;
            }else{
                set result=1;
            }
            ResetAll(q);
        }
        return result;
    }
}