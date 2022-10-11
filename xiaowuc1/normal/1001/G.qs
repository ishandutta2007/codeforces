namespace Solution {
    // H rotates zero to (0 + 1) and one to (0 - 1)
    // X flips value
    // Z flips sign
    // CNOT(a, b) flips b if a is true (entanglement)
    // CNOT can be repeated twice to undo the entanglement - https://codeforces.com/contest/1001/submission/50621093
    // M measures the qubit (collapse)
    // measuring one qubit in an entangled collection collapses all other qubits
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

    operation Solve (x : Qubit[], y : Qubit, k : Int) : Unit {
        CNOT(x[k], y);
    }

    operation RunQsharp() : Bool {
        using(qubits = Qubit[2]) {
            ResetAll(qubits);
        }
        return true;
    }
}