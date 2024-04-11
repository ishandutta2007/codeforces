namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Extensions.Math;
    open Microsoft.Quantum.Extensions.Convert;

    operation Solve (qs : Qubit[]) : () 
    {
        body
        {
            X(qs[0]);
            Helper(qs);
        }
    }

    operation Helper (qs : Qubit[]) : ()
    {
        body
        {
            if (Length(qs) == 1) {
            } else {
                let n = Length(qs);
                let half = n / 2;
                
                (Controlled H)([qs[0]], qs[half]);
                CNOT(qs[half], qs[0]);
                Helper(qs[0..half-1]);
                Helper(qs[half..n-1]);

            }
        }
    }

    operation RunQsharp () : Bool
    {
        body
        {
            mutable count = new Int[8];
            for (i in 1..1000) {
                using (qs = Qubit[8]) {
                    Solve(qs);
                    for (j in 0..Length(qs) - 1) {
                        if (M(qs[j]) == Zero) {
                            Message("0");
                        } else {
                            Message("1");
                            set count[j] =count[j] + 1; 
                        }
                    } 
                    ResetAll(qs);
                    Message("");
                }
            }
            for (j in 0..Length(count)-1) {
                Message(ToStringI(count[j]));
            }
            return true;
        }
    }
}