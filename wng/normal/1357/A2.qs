namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Measurement;

    operation Solve (unitary : (Qubit[] => Unit is Adj+Ctl)) : Int {
        mutable score=0;
         using (qs = Qubit[2]) {
            X(qs[0]);
            unitary(qs);
            //10 => 10  can be 0 or 2
            // 10 =>01 3
            // 10 => 11 1
            if (MResetZ(qs[1]) != Zero){
                return MResetZ(qs[0]) == Zero ? 3 | 1;
            }
            else {
                //10
                X(qs[1]);
                //11
                unitary(qs);
                X(qs[1]);
                return MResetZ(qs[0]) == Zero ? 2 | 0;
            }
         }
    }
}