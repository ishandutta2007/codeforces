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

    operation Solve (x : Qubit[], y : Qubit) : Unit {
        body (...) {
            let n = Length(x)-1;
            X(y);
            using(qubits = Qubit[n]) {
                for(i in 0..n-1) {
                    X(qubits[i]);
                    CNOT(x[i], qubits[i]);
                    CNOT(x[i+1], qubits[i]);
                }
                OrOracle(qubits, y);
                for(i in 0..n-1) {
                    CNOT(x[i], qubits[i]);
                    CNOT(x[i+1], qubits[i]);
                    X(qubits[i]);
                }
            }
        }
        adjoint auto;
    }

    // Message($"{variable_name_for_debugging}");
    operation RunQsharp() : Bool {

        using(qubits = Qubit[1]) {
        }
        return true;
    }
}