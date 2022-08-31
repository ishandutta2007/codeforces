namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
    operation Add (x : Qubit[]) : Unit {
        body (...) {
            //11->01->00
            using(tmp=Qubit[1])
            {
                Controlled X([x[0],x[1]],tmp[0]);
                CNOT(x[1],x[0]);
                X(x[0]); X(x[1]);
                CNOT(tmp[0],x[0]);
                CNOT(tmp[0],x[1]);
                X(x[0]);
                Controlled X([x[0],x[1]],tmp[0]);
                X(x[0]);
            }
        }
        controlled auto;
        adjoint auto;
        adjoint controlled auto;
    }
    operation Solve (x : Qubit[], y : Qubit) : Unit {
        body (...) {
            using(tmp=Qubit[2])
            {
                X(tmp[0]); X(tmp[1]);
                for(t in 0..2)
                {
                    for(g in 0..Length(x)-1)
                    {
                        Controlled Add([x[g]],tmp);
                    }
                    if(t==0)
                    {
                        Controlled X([tmp[0],tmp[1]],y);
                    }
                }
                X(tmp[0]); X(tmp[1]);
            }
        }
        adjoint auto;
    }
}