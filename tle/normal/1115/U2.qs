namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (q : Qubit, sign: Int) : Unit {
        body (...) {
            H(q);
            if(sign==-1)
            {
                Z(q);
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
    operation Test (sign: Int) : (Int) {
        mutable c1=0;
        for(i in 0..99)
        {
            using (q1=Qubit[1]){
                Set(Zero,q1[0]);
                Solve(q1[0],sign);
                if(M(q1[0])==One)
                {
                    set c1=c1+1;
                }
                Set(Zero,q1[0]);
            }
        }
        return (c1);
    }
}