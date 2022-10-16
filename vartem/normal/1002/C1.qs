namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Extensions.Math;
    open Microsoft.Quantum.Extensions.Convert;

    operation Solve (q : Qubit) : Int
    {
        body
        {
            Ry(PI() / ToDouble(4), q);
            let result = M(q);
            if (result == Zero) {
                return 0;
            } else {
                return 1;
            }
        }
    }

    operation RunQsharp () : Int
    {
        body
        {   
            mutable count = 0;
            for (i in 1..1000) {
                using (q = Qubit[1]) {
                    // H(q[0]);
                    if (Solve(q[0]) == 0) {
                        set count = count + 1;
                    }
                    Reset(q[0]);
                }
            }
            return count;
        }
    }
}