namespace Solution {
    // H rotates zero to (0 + 1) and one to (0 - 1)
    // X flips value (0 to 1, 1 to 0)
    // Z flips sign (0 to 0, 1 to -1)
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

    operation Solve (N : Int, Uf : ((Qubit[], Qubit) => Unit)) : Bool {
        mutable ret = true;
        using(qubits = Qubit[N]) {
            for(i in 0..N-1) {
                H(qubits[i]);
            }
            using(temp = Qubit[1]) {
                X(temp[0]);
                H(temp[0]);
                Uf(qubits, temp[0]);
                ResetAll(temp);
            }
            for(i in 0..N-1) {
                H(qubits[i]);
                if(M(qubits[i]) == One) {
                    set ret = false;
                }
            }
            ResetAll(qubits);
        }
        return ret;
    }

    operation Parity(x : Qubit[], y : Qubit) : Unit {
        let n = Length(x);
        for(i in 0..n-1) {
            CNOT(x[i], y);
        }
    }

    operation ReturnZero(x : Qubit[], y : Qubit) : Unit {

    }

    operation ReturnOne(x : Qubit[], y : Qubit) : Unit {
        X(y);
    }

    operation RunQsharp() : Bool {
        for(i in 1..10) {
            if(Solve(i, ReturnZero)) {
                Message("AC ZERO");
            }
            if(Solve(i, ReturnOne)) {
                Message("AC ONE");
            }
            if(not Solve(i, Parity)) {
                Message("AC PARITY");
            }
        }
        return true;
    }
}