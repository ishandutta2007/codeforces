namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Extensions.Math;
    open Microsoft.Quantum.Extensions.Convert;

    operation Solve (qs : Qubit[]) : Int
    {
        body
        {
            H(qs[0]);
            X(qs[0]);
            CNOT(qs[0], qs[1]);
            Z(qs[0]);
            H(qs[0]);
            return ResultAsInt([M(qs[1]); M(qs[0])]);
        }
    }

    operation RunQsharp () : Int
    {
        body
        {
            mutable res = 0;
            using (qs = Qubit[2]) {
                X(qs[1]);
                H(qs[0]);
                Z(qs[0]);
                CNOT(qs[0], qs[1]);
                X(qs[0]);
                H(qs[0]);
                set res = Solve(qs);
                ResetAll(qs);
            }
            return res;
        }
    }
}