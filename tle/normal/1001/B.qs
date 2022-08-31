namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[], index: Int) : Unit {
        body (...) {
            if(index%2==0)
            {
                H(qs[0]);
                CNOT(qs[0],qs[1]);
            }
            else
            {
                H(qs[0]);
                Z(qs[0]);
                CNOT(qs[0],qs[1]);
            }
            if(index>=2)
            {
                X(qs[1]);
            }
        }
    }
    operation Set (desired: Result, q1: Qubit) : Unit {
        let current = M(q1);
        if (desired != current)
        {
            X(q1);
        }
    }
    operation Test (sign: Int) : (Int,Int) {
        mutable c1=0;
        mutable ag=0;
        for(i in 0..99)
        {
            using (q1=Qubit[2]){
                Set(Zero,q1[0]);
                Set(Zero,q1[1]);
                Solve(q1,sign);
                let g=M(q1[0]);
                if(g==One)
                {
                    set c1=c1+1;
                }
                if(g==M(q1[1]))
                {
                    set ag=ag+1;
                }
                Set(Zero,q1[0]);
                Set(Zero,q1[1]);
            }
        }
        return (c1,ag);
    }
}