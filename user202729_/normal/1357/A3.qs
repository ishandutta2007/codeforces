namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Measurement;

    operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        using(q=Qubit()){
            unitary(q);
            Z(q);
            unitary(q);
            if(MResetZ(q)==One){return 0;}else{return 1;}
        }
    }
}