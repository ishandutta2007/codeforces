namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
    operation Set (desired: Result, q1: Qubit) : Unit {
        let current = M(q1);
        if (desired != current)
        {
            X(q1);
        }
    }
    operation f(q1:Qubit[],q2:Qubit): Unit {
        body(...)
        {
            CNOT(q1[0],q2);
            //X(q2);
            // for(i in 0..Length(q1)-1)
            // {
            //     CNOT(q1[i],q2);
            // }
        }
    }
    operation Solve (N : Int, Uf : ((Qubit[], Qubit) => Unit)) : Bool
    {
        body(...)
        {
            mutable rt=true;
            using (q1=Qubit[N]){
            using(q2=Qubit[1])
            {
                Set(One,q2[0]);
                for(i in 0..N-1)
                {
                    H(q1[i]);
                }
                H(q2[0]);
                Uf(q1,q2[0]);
                for(i in 0..N-1)
                {
                    H(q1[i]);
                }
                for(i in 0..N-1)
                {
                    if(M(q1[i])!=Zero)
                    {
                        set rt=false;
                    }
                }
                for(i in 0..N-1)
                {
                    Set(Zero,q1[i]);
                }
                Set(Zero,q2[0]);
            }}
            return rt;
        }
    }
    operation Test (n: Int) : Bool {
        return Solve(n,f);
    }
}