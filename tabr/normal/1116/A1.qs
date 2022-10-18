namespace Solution
{
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Arrays;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Diagnostics;
    open Microsoft.Quantum.Convert;
    open Microsoft.Quantum.Math;

    operation Solve (qs : Qubit[]) : Unit {
        let n = Length(qs);
        Ry(2.0 * ArcSin(1.0 / Sqrt(3.0)),qs[0]);
        CNOT(qs[0],qs[1]);
        (ControlledOnInt(0, H))(qs[1..1],qs[0]);
        CNOT(qs[1],qs[0]);
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
        // let unitary = ApplyToEach(I, _);
        let unitary = Solve;
        DumpUnitaryToFiles(N, unitary);
    }
}

// ApplyToEach(X, qs);
// Controlled X(qs, q);  ==  (ControlledOnInt(1, X))(qs, q); 
// ApplyToEach(Controlled X([q], _), qs);