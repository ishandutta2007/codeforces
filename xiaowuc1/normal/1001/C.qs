namespace Solution {
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

    operation Solve(qs : Qubit[]) : Unit {
        H(qs[0]);
        let n = Length(qs);
        for(i in 1..n-1) {
            CNOT(qs[0], qs[i]);
        }
    }

    operation RunQsharp() : Bool {
        using(qubits = Qubit[4]) {
            Solve(qubits);
            DM();
            ResetAll(qubits);
        }
        return true;
    }
}