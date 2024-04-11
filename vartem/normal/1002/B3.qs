namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Extensions.Convert;

    operation Solve (qs : Qubit[]) : Int
    {
        body
        {
            H(qs[0]);
            H(qs[1]);
            return ResultAsInt([M(qs[1]); M(qs[0])]);
        }
    }

    operation RunQsharp () : Bool
    {
        body
        {
            using (qs = Qubit[2]) {
                H(qs[0]);
                H(qs[1]);
                Z(qs[1]);
                Message(ToStringI(Solve(qs)));
                ResetAll(qs);
            }
            return true;
        }
    }
}