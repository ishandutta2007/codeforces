namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[], bits : Bool[][]) : Unit {
        using(tmp=Qubit[2])
        {
            H(tmp[0]);
            H(tmp[1]);
            let l=Length(bits[0]);
            for(i in 0..l-1) //status: 11
            {
                if(bits[0][i])
                {
                    Controlled X([tmp[0],tmp[1]],qs[i]);
                }
            }
            X(tmp[0]);
            for(i in 0..l-1) //status: 01
            {
                if(bits[1][i])
                {
                    Controlled X([tmp[0],tmp[1]],qs[i]);
                }
            }
            X(tmp[1]);
            for(i in 0..l-1) //status: 00
            {
                if(bits[2][i])
                {
                    Controlled X([tmp[0],tmp[1]],qs[i]);
                }
            }
            X(tmp[0]);
            for(i in 0..l-1) //status: 10
            {
                if(bits[3][i])
                {
                    Controlled X([tmp[0],tmp[1]],qs[i]);
                }
            }
            X(tmp[1]);
            for(i in 0..l-1) //status: 11
            {
                if(not bits[0][i])
                {
                    X(qs[i]);
                }
            }
            Controlled X(qs,tmp[0]);
            Controlled X(qs,tmp[1]);
            for(i in 0..l-1) //status: 11
            {
                if(not bits[0][i])
                {
                    X(qs[i]);
                }
            }
            for(i in 0..l-1) //status: 01
            {
                if(not bits[1][i])
                {
                    X(qs[i]);
                }
            }
            Controlled X(qs,tmp[1]);
            for(i in 0..l-1) //status: 01
            {
                if(not bits[1][i])
                {
                    X(qs[i]);
                }
            }
            for(i in 0..l-1) //status: 10
            {
                if(not bits[3][i])
                {
                    X(qs[i]);
                }
            }
            Controlled X(qs,tmp[0]);
            for(i in 0..l-1) //status: 10
            {
                if(not bits[3][i])
                {
                    X(qs[i]);
                }
            }
        }
    }
}