namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
    //quite hard
    operation Solve (qs : Qubit[]) : Unit
    {
        body(...)
        {
            let k=Length(qs);
            if(k==1)
            {
                X(qs[0]);
                return ();
            }
            Solve(qs[0..k/2-1]);
            using(tmp=Qubit[1])
            {
                H(tmp[0]);
                for(i in 0..k/2-1)
                {
                    Controlled SWAP([tmp[0]],(qs[i],qs[i+k/2]));
                }
                for(i in k/2..k-1)
                {
                    CNOT(qs[i],tmp[0]);
                }
            }
        }
    }
}