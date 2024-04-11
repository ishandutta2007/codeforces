namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[], bits0 : Bool[], bits1 : Bool[]) : Int
    {
        body
        {
            for (i in 0..Length(bits0) - 1) {
                if (bits0[i] != bits1[i]) {
                    let result = M(qs[i]);
                    if ((result == Zero) == (bits0[i] == false)) {
                        return 0;
                    } else {
                        return 1;
                    }
                }
            }
            return -1;
        }
    }

    // operation SolutionTest (index: Int) : Int
    // {
    //     body
    //     {
    //         mutable result = 0;
    //         using (qs = Qubit[2]) {
    //             ResetAll(qs);
    //             H(qs[0]);
    //             CNOT(qs[0], qs[1]);
    //             if (index % 2 == 1) {
    //                 Z(qs[1]);
    //             }
    //             if (index / 2 == 1) {
    //                 X(qs[1]);
    //             }
    //             set result = Solve(qs);
    //             ResetAll(qs);
    //         }
    //         return result;
    //     }
    // }
}