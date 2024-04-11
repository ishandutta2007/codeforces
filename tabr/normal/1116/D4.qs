namespace Solution
{
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Arrays;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Diagnostics;
    open Microsoft.Quantum.Convert;

    operation Solve (qs : Qubit[]) : Unit {
        let n = Length(qs);
        X(qs[n-1]);
        for(i in 0..n-2){
            CNOT(qs[n-1], qs[i]);
        }
        X(qs[n-1]);
        X(qs[0]);
        for (i in 1..n-2) {
            (Controlled X)(qs[0..i-1], qs[i]);
        }
        H(qs[n-1]);
        for(i in 0..n-2){
            CNOT(qs[n-1], qs[i]);
        }
    }

    operation Reflect (qs : Qubit[]) : Unit {
        body (...) {
            ApplyToEachC(X, qs);
        }
        controlled auto;
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