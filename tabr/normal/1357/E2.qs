namespace Solution {
    open Microsoft.Quantum.Arithmetic;
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Arrays;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Diagnostics;
    open Microsoft.Quantum.Convert;
    open Microsoft.Quantum.Math;
    
    operation Solve (p : Int, qs : LittleEndian) : Unit is Adj + Ctl {
        let n = Length(qs!);
        let s = 1.0 / IntAsDouble(p);
        using ((a, b) = (Qubit(), Qubit())) {
            H(a);
            H(b);
            Controlled QFTLE([a], qs);
            for (i in 0 .. n - 1) {
                CNOT(b, qs![i]);
            }
            Controlled Increment([b], qs);
            Adjoint QFTLE(LittleEndian([a, b]));
            R1(s * PI() / 2.0, a);
            R1(s * PI(), b);
            QFTLE(LittleEndian([a, b]));
            Controlled Decrement([b], qs);
            for (i in 0 .. n - 1) {
                CNOT(b, qs![i]);
            }
            Controlled Adjoint QFTLE([a], qs);
            H(a);
            H(b);
        }
    }

    operation Solvee(qs : LittleEndian) : Unit {
        let n = Length(qs!);
        let s = 1.0;
        using ((a, b) = (Qubit(), Qubit())) {
            H(a);
            H(b);
            Controlled QFTLE([a], qs);
            for (i in 0 .. n - 1) {
                CNOT(b, qs![i]);
            }
            Controlled Increment([b], qs);
            Adjoint QFTLE(LittleEndian([a, b]));
            R1(s * PI() / 2.0, a);
            R1(s * PI(), b);
            QFTLE(LittleEndian([a, b]));
            Controlled Decrement([b], qs);
            for (i in 0 .. n - 1) {
                CNOT(b, qs![i]);
            }
            Controlled Adjoint QFTLE([a], qs);
            H(a);
            H(b);
        }
    }

    operation Increment (r : LittleEndian) : Unit is Adj + Ctl {
        let n = Length(r!);
        for (i in n - 1..-1..1) {
            Controlled X(r![0..i - 1], r![i]);
        }
        X(r![0]);
    }

    operation Decrement (r: LittleEndian) : Unit is Adj + Ctl {
        Adjoint Increment(r);
    }

    operation DumpUnitaryToFiles (N : Int, unitary : (LittleEndian => Unit)) : Unit {
        let size = 1 <<< N;
        using (qs = Qubit[N]) {
            for (k in 0 .. size - 1) {                
                let binary = IntAsBoolArray(k, N);
                ApplyPauliFromBitString(PauliX, true, binary, qs);
                unitary(LittleEndian(qs));
                DumpMachine($"DU_{N}_{k}.txt");
                ResetAll(qs);
            }
        }
    }

    operation CallDumpUnitary (N : Int) : Unit {
        DumpUnitaryToFiles(N, Solvee);
    }
}