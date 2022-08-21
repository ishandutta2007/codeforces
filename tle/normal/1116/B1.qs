namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
    operation Produce (qs : Qubit[]) : Unit {
        body(...)
        {
            Ry(-1.9106332362490185960979260926251299679279327392578125,qs[0]); //-2atan(sqrt(2))
            Controlled Ry([qs[0]],(1.5707963267948965579989817342720925807952880859375,qs[1])); //pi/2
            Controlled Rz([qs[0]],(2.094395102393195262635572362341918051242828369140625,qs[1])); //pi*2/3
            Controlled X([qs[1]],qs[2]);
            Controlled X([qs[0]],qs[1]);
            X(qs[0]);
        }
        adjoint auto;
    }
    operation Solve (qs : Qubit[]) : Int {
        Adjoint(Produce)(qs);
        mutable c1=0;
        for(i in 0..2)
        {
            if(M(qs[i])==One)
            {
                set c1=c1+1;
            }
        }
        if(c1==0)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
}