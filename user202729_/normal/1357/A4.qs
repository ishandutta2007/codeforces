namespace Solution{
open Microsoft.Quantum.Intrinsic;
open Microsoft.Quantum.Math;
open Microsoft.Quantum.Measurement;

    operation Solve (unitary : ((Double, Qubit) => Unit is Adj+Ctl)) : Int {
        using(q=Qubit[2]){
            H(q[0]);
            CNOT(q[0], q[1]);
            
            Controlled unitary([q[0]], (2.*PI(), q[1]));
            CNOT(q[0], q[1]);
            H(q[0]);
            if(MResetZ(q[0])==Zero){return 1;}else{return 0;}
        }
    }
    }