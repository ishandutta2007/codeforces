namespace Solution
{
    open Microsoft.Quantum.Arithmetic;
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Arrays;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Diagnostics;
    open Microsoft.Quantum.Convert;
    open Microsoft.Quantum.Math;

    operation Solve (p : Int, qs : LittleEndian) : Unit is Adj+Ctl {
        // if ((p % 2) == 1) {
        //     for (i in 1..p % 4) {
        //         QFTLE(qs);
        //     }
        // } else {
            let a = LittleEndianAsBigEndian(qs);
        //     QuantumFourierTransform_Reference(a!, p);
        // }
        for (i in 1..p % 4) {
            QuantumFourierTransform_Reference(a!, p);
        }
    }

    // 3, 7 -> 3 times
    // 5 -> 1 time
    // 2, 4, 6, 8 -> ?

    operation Solvee(qs:Qubit[]) : Unit {
        // QuantumFourierTransform_Reference(qs, 2);
        QFT(BigEndian(qs));
    }

    operation OneQubitQFT_Reference (q : Qubit, p : Int) : Unit is Adj+Ctl {
        H(q);
    }

    // Task 1.2. Rotation gate
    operation Rotation_Reference (q : Qubit, k : Int, p : Int) : Unit is Adj+Ctl {
        // R1Frac(2 * p, k, q);
        R1(2.0 * PI() / IntAsDouble(1 <<< k), q);
    }

    // Task 1.5. Prepare binary fraction exponent in place (quantum input)
    // Input: A register of qubits in state |jj...j
    // Goal: Change the state of the register
    //       from |j  |j...j
    //         to 1/sqrt(2) (|0 + exp(2i  0.jj...j) |1)  |j...j.
    operation BinaryFractionQuantumInPlace_Reference (register : Qubit[], p : Int) : Unit is Adj+Ctl {
        OneQubitQFT_Reference(register[0], p);
        for (ind in 1 .. Length(register) - 1) {
            Controlled Rotation_Reference([register[ind]], (register[0], ind + 1, p));
        }
    }

    // Task 1.6. Reverse the order of qubits
    // Input: A register of qubits in state |xx...x
    // Goal: Reverse the order of qubits, i.e., convert the state of the register to |x...xx.
    operation ReverseRegister_Reference (register : Qubit[]) : Unit is Adj+Ctl {
        let N = Length(register);
        for (ind in 0 .. N / 2 - 1) {
            SWAP(register[ind], register[N - 1 - ind]);
        }
    }


    // Task 1.7. Quantum Fourier transform
    // Input: A register of qubits in state |jj...j
    // Goal: Apply quantum Fourier transform to the input register, i.e.,
    //       transform it to a state 
    //       1/sqrt(2) (|0 + exp(2i  0.j) |1) 
    //       1/sqrt(2) (|0 + exp(2i  0.jj) |1)  ... 
    //       1/sqrt(2) (|0 + exp(2i  0.jj...jj) |1) 
    operation QuantumFourierTransform_Reference (register : Qubit[], p : Int) : Unit is Adj+Ctl {
        let n = Length(register);
        for (i in 0 .. n - 1) {
            BinaryFractionQuantumInPlace_Reference(register[i ...], p);
        }
        ReverseRegister_Reference(register);
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
        let unitary = Solvee;
        DumpUnitaryToFiles(N, unitary);
    }
}

// ApplyToEach(X, qs);
// Controlled X(qs, q);  ==  (ControlledOnInt(1, X))(qs, q); 
// ApplyToEach(Controlled X([q], _), qs);