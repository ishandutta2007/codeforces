namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Diagnostics;
    open Microsoft.Quantum.Convert;
    open Microsoft.Quantum.Math;
 
    operation Solve (theta : Double, unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        mutable rt=-1;
        mutable res0=One;
        mutable res1=One;
        using(x=Qubit[2]) {
            repeat {
                let num=RandomInt(100);
                H(x[0]);
                CNOT(x[0],x[1]);
                (Controlled R)([x[0]], (PauliZ, -theta*IntAsDouble(num), x[1]));
                for(stp in 0..num-1) {(Controlled unitary)([x[0]],x[1]);}
                CNOT(x[0],x[1]);
                H(x[0]);
                set res0=M(x[0]);
                set res1=M(x[1]);
                if(res0==One or res1==One) {ResetAll(x); set rt=1;}
                H(x[0]);
                CNOT(x[0],x[1]);
                (Controlled R)([x[0]], (PauliY, -theta*IntAsDouble(num), x[1]));
                for(stp in 0..num-1) {(Controlled unitary)([x[0]],x[1]);}
                CNOT(x[0],x[1]);
                H(x[0]);
                set res0=M(x[0]);
                set res1=M(x[1]);
                if(res0==One or res1==One) {ResetAll(x); set rt=0;}
            }
            until (rt!=-1);
        }
        return rt;
    }
}