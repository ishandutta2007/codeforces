namespace Solution
{
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Extensions.Bitwise;

    operation Solve (x : Qubit[], y : Qubit, k : Int) : ()
    {
        body
        {
            CNOT(x[k], y);
        }
    }
}