namespace Solution
{
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Arrays;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Diagnostics;
    open Microsoft.Quantum.Convert;
    open Microsoft.Quantum.Math;

    // operation Solve (qs : Qubit[]) : Unit {
    //     let n = Length(qs);
    // }

    // operation Solve (unitary : (Qubit => Unit is Adj + Ctl)) : Int {
    //     using (q = Qubit()) {
    //         let m = M(q); 
    //         Set(Zero, q);
    //         if (m == One) {
    //             return 1;
    //         } else {
    //             return 0;
    //         }
    //     }
    // }

    operation Solve (unitary : (Qubit[] => Unit is Adj+Ctl)) : Int {
        using (qs=Qubit[2]){
            unitary(qs);
            let m = M(qs[1]);
            Set(Zero,qs[0]);
            Set(Zero,qs[1]);
            if(m!=One){
                return 1;
            }else{
                return 0;
            }
        }
    }

    operation Set (desired: Result, q1: Qubit) : Unit {
        let current = M(q1);
        if (desired != current) { X(q1); }
    }

    operation DumpUnitaryToFiles (N : Int, unitary : (Qubit[] => Unit)) : Unit {
        let size = 1 <<< N;
        using (qs = Qubit[N]) {
            for (k in 0 .. size - 1) {                
                let binary = IntAsBoolArray(k, N);
                ApplyPauliFromBitString(PauliX, true, binary, qs);
                unitary(qs);
                DumpMachine($"DU_{N}_{k}.txt");
                ResetAll(qs);
            }
        }
    }

    operation CallDumpUnitary (N : Int) : Unit {
        let unitary = ApplyToEach(I, _);
        // let unitary = Solve;
        DumpUnitaryToFiles(N, unitary);
    }
}

// ApplyToEach(X, qs);
// Controlled X(qs, q);  ==  (ControlledOnInt(1, X))(qs, q); 
// ApplyToEach(Controlled X([q], _), qs);