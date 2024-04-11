namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : Unit {
        let Rt=Ry(0.57,_);
        for(i in 0..Length(qs)-1)
        {
            for(j in i-1..-1..0)
            {
                Controlled Rt([qs[i]],qs[j]);
            }
        }
    }
}