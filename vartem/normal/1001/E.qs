namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : Int
    {
        body
        {
            // ResetAll(qs);
            // H(qs[0]);
            // CNOT(qs[0], qs[1]);
            // if (index % 2 == 1) {
            //     Z(qs[1]);
            // }
            // if (index / 2 == 1) {
            //     X(qs[1]);
            // }
            CNOT(qs[0], qs[1]);
            H(qs[0]);
            return ResultAsInt([M(qs[0]); M(qs[1])]);
        }
    }
}