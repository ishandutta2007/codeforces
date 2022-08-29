namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (q : Qubit) : Int
    {
        body
        {
            H(q);
            let m = M(q);
            if (m == Zero) {
                return 1;
            }
            else {
                return -1;
            }
        }
    }
}