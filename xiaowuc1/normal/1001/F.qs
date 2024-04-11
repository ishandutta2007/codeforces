namespace Solution {
    // H rotates zero to (0 + 1) and one to (0 - 1)
    // X flips value
    // Z flips sign
    // CNOT(a, b) flips b if a is true (entanglement)
    // CNOT can be repeated twice to undo the entanglement - https://codeforces.com/contest/1001/submission/50621093
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

    operation Solve (qs : Qubit[], bits0 : Bool[], bits1 : Bool[]) : Int {
        let n = Length(qs);
        for(i in 0..n-1) {
            let res = M(qs[i]);
            if((res == One) != bits0[i]) {
                return 1;
            }
            if((res == One) != bits1[i]) {
                return 0;
            }
        }
        return -1;
    }

    operation RunQsharp() : Bool {
        using(qubits = Qubit[2]) {
            ResetAll(qubits);
        }
        return true;
    }
}