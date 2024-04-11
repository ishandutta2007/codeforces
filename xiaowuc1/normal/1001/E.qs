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

    operation Solve(qs : Qubit[]) : Int {
        CNOT(qs[0], qs[1]);
        H(qs[0]);
        if(M(qs[0]) == Zero && M(qs[1]) == Zero) {
            return 0;
        }
        if(M(qs[0]) == One && M(qs[1]) == Zero) {
            return 1;
        }
        if(M(qs[0]) == Zero && M(qs[1]) == One) {
            return 2;
        }
        if(M(qs[0]) == One && M(qs[1]) == One) {
            return 3;
        }
        return -1;
    }

    operation GenerateBellState(qs : Qubit[], index : Int) : Unit {
        ResetAll(qs);
        if(index == 0) {
            H(qs[0]);
            CNOT(qs[0], qs[1]);
        }
        if(index == 1) {
            H(qs[0]);
            Z(qs[0]);
            CNOT(qs[0], qs[1]);
        }
        if(index == 2) {
            H(qs[0]);
            CNOT(qs[0], qs[1]);
            X(qs[1]);
        }
        if(index == 3) {
            H(qs[0]);
            Z(qs[0]);
            CNOT(qs[0], qs[1]);
            X(qs[1]);
        }
    }

    operation RunQsharp() : Bool {
        using(qubits = Qubit[2]) {
            for(i in 0..3) {
                GenerateBellState(qubits, i);
                let x = Solve(qubits);
                if(i == x) {
                    Message("AC");
                }
                DM();
            }
            ResetAll(qubits);
        }
        return true;
    }
}