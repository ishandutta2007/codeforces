namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : Unit {
       for(i in 0..Length(qs)-2)
        {
            CNOT(qs[Length(qs)-1],qs[i]);
        }
        for(i in Length(qs)-2..-1..0)
        {
            Controlled X(qs[0..i-1],qs[i]);
        }
        H(qs[Length(qs)-1]);
        for(i in 0..Length(qs)-2)
        {
            CNOT(qs[Length(qs)-1],qs[i]);
            X(qs[i]);
        }
    }
}