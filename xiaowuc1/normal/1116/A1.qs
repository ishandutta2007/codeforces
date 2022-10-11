namespace Solution {
    // H rotates zero to (0 + 1) and one to (0 - 1)
    // X flips value (0 to 1, 1 to 0)
    // (Controlled X) takes in (control array, qubit) and flips qubit iff all qubits in control array are true - https://codeforces.com/contest/1115/submission/50621387
    // Z flips sign (0 to 0, 1 to -1)
    // CNOT(a, b) flips b if a is true (entanglement)
    // CNOT can be repeated twice to undo the entanglement - https://codeforces.com/contest/1001/submission/50621093
    // M measures the qubit (collapse)
    // measuring one qubit in an entangled collection collapses all other qubits

    // Do not corrupt input qubits! https://codeforces.com/contest/1115/submission/50621453
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Extensions.Convert;
    open Microsoft.Quantum.Extensions.Diagnostics;
    open Microsoft.Quantum.Extensions.Math;
    // to get Pi, use PI()
    open Microsoft.Quantum.Extensions.Testing;

    // this dumps the state of the machine
    operation DM(): Unit {
        DumpMachine("");
    }

    // this sets the given qubit to be equal to the value "desired"
    // NB: desired must be either zero or one
    operation Set (desired: Result, q1: Qubit) : Unit {
        let current = M(q1);
        if(desired != current) {
            X(q1);
        }
    }

    operation AndOracle(x : Qubit[], y : Qubit) : Unit {
        // returns 1 iff everything in x is true
        body (...) {
            (Controlled X)(x, y);
        }
        adjoint auto;
    }

    operation OrOracle(x : Qubit[], y : Qubit) : Unit {
        body (...) {
            let n = Length(x);
            for(i in 0..n-1) {
                // negate them
                X(x[i]);
            }
            X(y);
            (Controlled X)(x, y);
            for(i in 0..n-1) {
                // negate them back
                X(x[i]);
            }
        }
        adjoint auto;
    }

    operation ComputeAndOracle(x: Qubit[], z : Qubit, k : Int) : Unit {
        // period k, z
        body (...) {
            let n = Length(x);
            using(qubits = Qubit[n-k]) {
                for(i in 0..n-k-1) {
                    X(qubits[i]);
                    CNOT(x[i], qubits[i]);
                    CNOT(x[i+k], qubits[i]);
                }
                AndOracle(qubits, z);
                for(i in 0..n-k-1) {
                    X(qubits[i]);
                    CNOT(x[i], qubits[i]);
                    CNOT(x[i+k], qubits[i]);
                }
            }
        }
        adjoint auto;
    }

    operation SqrtSwap(a: Qubit, b: Qubit) : Unit {
        body (...) {
            // Z = Z^1 (pi)
            // S = Z^(1/2) (pi/2)
            // T = Z^(1/4) (pi/4)
            CNOT(a, b);
            H(a);
            R1(PI()/4., a);
            H(a);
            R1(-PI()/4., b);
            H(b);
            CNOT(a, b);
            H(a);
            R1(-PI()/4., a);
            H(a);
            H(b);
            CNOT(a, b);
            R1(-PI()/2., a);
            R1(PI()/2., b);
        }
    }

    operation Solve (qs : Qubit[])  : Unit {
        body (...) {
            let theta = ArcSin(1.0 / Sqrt(1.5));
            Ry(2.0 * theta, qs[1]);
            SqrtSwap(qs[0], qs[1]);
            let constant = 0.8225;
            R1(PI()/4., qs[0]);
            R1(-PI()/4., qs[1]);
        }
    }

    // Message($"{variable_name_for_debugging}");
    operation RunQsharp() : Bool {

        using(qubits = Qubit[2]) {
            Solve(qubits);
            ResetAll(qubits);
        }
        return true;
    }
}