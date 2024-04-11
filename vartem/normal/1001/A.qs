namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (q : Qubit, sign : Int) : ()
    {
        body
        {
            let current = M(q);
            if (current != Zero) {
                X(q);
            }
            H(q);
            if (sign == -1) {
                Z(q);
            }
        }
    }
}