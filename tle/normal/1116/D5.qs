namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : Unit {
        for(i in 0..1)
        {
            CNOT(qs[2],qs[i]);
        }
        H(qs[2]);
        for(i in 0..1)
        {
            CNOT(qs[2],qs[i]);
        }
        CNOT(qs[1],qs[2]);
        X(qs[2]);
        Controlled H([qs[2]],qs[0]);
        X(qs[2]);
        CNOT(qs[1],qs[2]);
        CNOT(qs[1],qs[2]);
        X(qs[0]);
        Controlled X([qs[2],qs[0]],qs[1]);
        CNOT(qs[1],qs[2]);
        X(qs[0]);
    }
}