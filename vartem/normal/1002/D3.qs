namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Extensions.Convert;

    operation Solve (x : Qubit[], y : Qubit) : ()
    {
        body
        {
            (Controlled X)([x[0]; x[1]], y);
            (Controlled X)([x[1]; x[2]], y);
            (Controlled X)([x[0]; x[2]], y);
        }
    }

    operation RunQsharp () : Bool
    {
        body
        {
            using (x = Qubit[3]) {
                using (y = Qubit[1]) {
                    // X(x[0]);
                    X(x[1]);
                    X(x[2]);
                    Solve(x, y[0]);
                    Message(ToStringI(ResultAsInt([M(y[0])])));
                    ResetAll(x);
                    ResetAll(y);
                }
            }
            return true;
        }
    }
}