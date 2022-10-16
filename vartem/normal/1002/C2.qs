namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Extensions.Math;
    open Microsoft.Quantum.Extensions.Convert;

    operation Solve (q : Qubit) : Int
    {
        body
        {
            if (RandomInt(2) == 0) {
                let result = M(q);
                if (result == One) {
                    return 1;
                } else {
                    return -1;
                }
            } else {
                H(q);
                let result = M(q);
                if (result == One) {
                    return 0;
                } else {
                    return -1;
                }
            }
        }
    }

    operation RunQsharp () : Int
    {
        body
        {   
            mutable count0 = 0;
            mutable count1 = 0;
            
            for (i in 1..1000) {
                using (q = Qubit[1]) {
                    H(q[0]);
                    let returned = Solve(q[0]);
                    if (returned == 0) {
                        set count0 = count0 + 1;
                    } elif (returned == 1) {
                        set count1 = count1 + 1;
                    }
                    Reset(q[0]);
                }
            }
            Message(ToStringI(count0));
            return count1;
        }
    }
}