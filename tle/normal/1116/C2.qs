namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
    operation Solve (x : Qubit[], y : Qubit) : Unit {
        body (...) {
            using(t=Qubit[Length(x)-1])
            {
                for(p in 1..Length(x)-1)
                {
                    X(t[p-1]);
                    for(j in 0..Length(x)-p-1)
                    {
                        CNOT(x[j+p],x[j]);
                        X(x[j]);
                    }
                    Controlled X(x[0..Length(x)-p-1],t[p-1]);
                    for(j in Length(x)-p-1..-1..0)
                    {
                        X(x[j]);
                        CNOT(x[j+p],x[j]);
                    }
                }
                X(y);
                Controlled X(t,y);
                for(p in 1..Length(x)-1)
                {
                    X(t[p-1]);
                    for(j in 0..Length(x)-p-1)
                    {
                        CNOT(x[j+p],x[j]);
                        X(x[j]);
                    }
                    Controlled X(x[0..Length(x)-p-1],t[p-1]);
                    for(j in Length(x)-p-1..-1..0)
                    {
                        X(x[j]);
                        CNOT(x[j+p],x[j]);
                    }
                }
            }
        }
        adjoint auto;
    }
}