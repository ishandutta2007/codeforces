namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (x : Qubit[], y : Qubit) : ()
    {
        body
        {
            let n=Length(x);
            for(i in 0..n-1)
            {
                CNOT(x[i],y);
            }
        }
    }
}