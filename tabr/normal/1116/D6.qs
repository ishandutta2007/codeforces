namespace Solution
{
    open Microsoft.Quantum.Arithmetic;
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Arrays;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Diagnostics;
    open Microsoft.Quantum.Convert;
    open Microsoft.Quantum.Math;

    operation Solve (qs : Qubit[]) : Unit {
        let n = Length(qs);
        for(i in 0..((1<<<n)-2)){
            Controlled H(qs[1..n-1],qs[0]);
            Increment(qs);
        }
        Increment(qs);
    }

    operation Increment (r : Qubit[]) : Unit is Adj + Ctl {
        let n = Length(r);
        for (i in n - 1..-1..1) {
            Controlled X(r[0..i - 1], r[i]);
        }
        X(r[0]);
    }

    operation Decrement (r : Qubit[]) : Unit is Adj + Ctl {
        let n = Length(r);
        for (i in 0..n - 1) {
            X(r[i]);
        }
        Increment(r);
        for (i in 0..n - 1) {
            X(r[i]);
        }
    }

    operation Deutsch_Jozsa (n : Int, U : ((Qubit[], Qubit) => Unit)) : Bool {
        mutable res = true;
        using ((x, y) = (Qubit[n], Qubit())) {
            X(y);
            H(y);
            for (i in 0..n - 1) {
                H(x[i]);
            }
            U(x, y);
            H(y);
            for (i in 0..n - 1) {
                H(x[i]);
                if (M(x[i]) != Zero) {
                    set res = false;
                }
            }
            ResetAll(x);
            Reset(y);
        }
        return res;
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
        // let unitary = ApplyToEach(I, _);
        let unitary = Solve;
        DumpUnitaryToFiles(N, unitary);
    }
}

// ApplyToEach(X, qs);
// Controlled X(qs, q);  ==  (ControlledOnInt(1, X))(qs, q); 
// ApplyToEach(Controlled X([q], _), qs);