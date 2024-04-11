namespace Solution {
    // H rotates zero to (0 + 1) and one to (0 - 1)
    // X flips value
    // Z flips sign
    // CNOT(a, b) flips b if a is true (entanglement)
    // M measures the qubit (collapse)
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Extensions.Diagnostics;
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

    operation Solve(q : Qubit) : Int {
        H(q);
        if(M(q) == One) {
            return -1;
        }
        else {
            return 1;
        }
    }

    operation RunQsharp() : Bool {
        using(qubits = Qubit[1]) {
            H(qubits[0]);
            let x1 = Solve(qubits[0]);
            DM();
            if(x1 == 1) {
                Message("AC1");
            }
            ResetAll(qubits);
            H(qubits[0]);
            Z(qubits[0]);
            let x2 = Solve(qubits[0]);
            if(x2 == -1) {
                Message("AC2");
            }
            DM();
            ResetAll(qubits);
        }
        return true;
    }
}