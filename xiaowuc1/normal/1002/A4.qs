namespace Solution {
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Extensions.Diagnostics;
    open Microsoft.Quantum.Extensions.Testing;

    operation DM() : () {
        body {
            DumpMachine("/dev/stdout");
        }
    }

    operation ThreeBitAnd (q1: Qubit, q2: Qubit, q3: Qubit, ret: Qubit) :()
    {
        body
        {
            using(t=Qubit[2]) {
                CCNOT(q1, q2, t[0]);
                CCNOT(q3, t[0], t[1]);
                CNOT(t[1], ret);
                CCNOT(q3, t[0], t[1]);
                CCNOT(q1, q2, t[0]);
            }
        }
    }

    operation FourBitAnd (q1: Qubit, q2: Qubit, q3: Qubit, q4: Qubit, ret: Qubit) :()
    {
        body
        {
            (Controlled X)([q1; q2; q3; q4], ret);
        }
    }

    

    operation Set (desired: Result, q1: Qubit) : ()
    {
        body
        {
            let current = M(q1);
            if (desired != current)
            {
                X(q1);
            }
        }
    }

    operation Solve (qs : Qubit[]) : ()
    {
        body
        {
            if(Length(qs) == 1) {
                Set(One, qs[0]);
            }
            elif(Length(qs) == 2) {
                H(qs[0]);
                CNOT(qs[0], qs[1]);
                X(qs[1]);
            }
            elif(Length(qs) == 4) {
                using(t=Qubit[2]) {
                    H(t[0]);
                    H(t[1]);

                    CCNOT(t[0], t[1], qs[0]);
                    X(t[0]);
                    CCNOT(t[0], t[1], qs[1]);
                    X(t[1]);
                    CCNOT(t[0], t[1], qs[2]);
                    X(t[0]);
                    CCNOT(t[0], t[1], qs[3]);
                    X(t[1]);

                    CNOT(qs[0], t[0]);
                    CNOT(qs[3], t[0]);
                    CNOT(qs[0], t[1]);
                    CNOT(qs[1], t[1]);
                }
            }
            elif(Length(qs) == 8) {
                using(t=Qubit[3]) {
                    H(t[0]);
                    H(t[1]);
                    H(t[2]);

                    ThreeBitAnd(t[0], t[1], t[2], qs[0]);
                    X(t[0]);
                    ThreeBitAnd(t[0], t[1], t[2], qs[1]);
                    X(t[1]);
                    ThreeBitAnd(t[0], t[1], t[2], qs[2]);
                    X(t[0]);
                    ThreeBitAnd(t[0], t[1], t[2], qs[3]);
                    X(t[2]);
                    ThreeBitAnd(t[0], t[1], t[2], qs[4]);
                    X(t[0]);
                    ThreeBitAnd(t[0], t[1], t[2], qs[5]);
                    X(t[1]);
                    ThreeBitAnd(t[0], t[1], t[2], qs[6]);
                    X(t[0]);
                    ThreeBitAnd(t[0], t[1], t[2], qs[7]);
                    X(t[2]);


                    CNOT(qs[0], t[0]);
                    CNOT(qs[3], t[0]);
                    CNOT(qs[4], t[0]);
                    CNOT(qs[7], t[0]);
                    
                    CNOT(qs[0], t[1]);
                    CNOT(qs[1], t[1]);
                    CNOT(qs[6], t[1]);
                    CNOT(qs[7], t[1]);
                    
                    CNOT(qs[0], t[2]);
                    CNOT(qs[1], t[2]);
                    CNOT(qs[2], t[2]);
                    CNOT(qs[3], t[2]);

                }
                
            }
            elif(Length(qs) == 16) {
                using(t=Qubit[4]) {
                    H(t[0]);
                    H(t[1]);
                    H(t[2]);
                    H(t[3]);

                    FourBitAnd(t[0], t[1], t[2], t[3], qs[0]);
                    X(t[0]);
                    FourBitAnd(t[0], t[1], t[2], t[3], qs[1]);
                    X(t[1]);
                    FourBitAnd(t[0], t[1], t[2], t[3], qs[2]);
                    X(t[0]);
                    FourBitAnd(t[0], t[1], t[2], t[3], qs[3]);
                    X(t[2]);
                    FourBitAnd(t[0], t[1], t[2], t[3], qs[4]);
                    X(t[0]);
                    FourBitAnd(t[0], t[1], t[2], t[3], qs[5]);
                    X(t[1]);
                    FourBitAnd(t[0], t[1], t[2], t[3], qs[6]);
                    X(t[0]);
                    FourBitAnd(t[0], t[1], t[2], t[3], qs[7]);
                    X(t[3]);
                    FourBitAnd(t[0], t[1], t[2], t[3], qs[8]);
                    X(t[0]);
                    FourBitAnd(t[0], t[1], t[2], t[3], qs[9]);
                    X(t[1]);
                    FourBitAnd(t[0], t[1], t[2], t[3], qs[10]);
                    X(t[0]);
                    FourBitAnd(t[0], t[1], t[2], t[3], qs[11]);
                    X(t[2]);
                    FourBitAnd(t[0], t[1], t[2], t[3], qs[12]);
                    X(t[0]);
                    FourBitAnd(t[0], t[1], t[2], t[3], qs[13]);
                    X(t[1]);
                    FourBitAnd(t[0], t[1], t[2], t[3], qs[14]);
                    X(t[0]);
                    FourBitAnd(t[0], t[1], t[2], t[3], qs[15]);
                    X(t[3]);
                    
                    CNOT(qs[0], t[0]);
                    CNOT(qs[3], t[0]);
                    CNOT(qs[4], t[0]);
                    CNOT(qs[7], t[0]);
                    CNOT(qs[8], t[0]);
                    CNOT(qs[11], t[0]);
                    CNOT(qs[12], t[0]);
                    CNOT(qs[15], t[0]);
                    
                    
                    CNOT(qs[0], t[1]);
                    CNOT(qs[1], t[1]);
                    CNOT(qs[6], t[1]);
                    CNOT(qs[7], t[1]);
                    CNOT(qs[8], t[1]);
                    CNOT(qs[9], t[1]);
                    CNOT(qs[14], t[1]);
                    CNOT(qs[15], t[1]);
                    
                    CNOT(qs[0], t[2]);
                    CNOT(qs[1], t[2]);
                    CNOT(qs[2], t[2]);
                    CNOT(qs[3], t[2]);
                    CNOT(qs[12], t[2]);
                    CNOT(qs[13], t[2]);
                    CNOT(qs[14], t[2]);
                    CNOT(qs[15], t[2]);
                    
                    CNOT(qs[0], t[3]);
                    CNOT(qs[1], t[3]);
                    CNOT(qs[2], t[3]);
                    CNOT(qs[3], t[3]);
                    CNOT(qs[4], t[3]);
                    CNOT(qs[5], t[3]);
                    CNOT(qs[6], t[3]);
                    CNOT(qs[7], t[3]);
                    
                }
            }
        }
    }

    operation RunQsharp() : () {
        body {
            using(qs=Qubit[16]) {
                Solve(qs);
                // DM();
                ResetAll(qs);
            }
        }
    }
}