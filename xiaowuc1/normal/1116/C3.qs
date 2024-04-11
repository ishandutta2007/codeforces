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
    operation DM(s: String): Unit {
        Message(s);
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
        controlled auto;
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
        controlled auto;
    }

    operation XorOracle(qs : Qubit[], bits: Bool[]) : Unit {
        body(...) {
            let n = Length(qs);
            for(i in 0..n-1) {
                if(bits[i]) {
                    X(qs[i]);
                }
            }
        }
        adjoint auto;
        controlled auto;
    }

    operation AddOne(qs: Qubit[], idx: Int) : Unit {
        body(...) {
            if(idx == 3) {
                X(qs[3]);
            }
            else {
                Controlled AddOne(qs[idx..idx], (qs, idx+1));
                X(qs[idx]);
            }
        }
        adjoint auto;
        controlled auto;
    }

    operation SubtractOne(qs: Qubit[], idx: Int) : Unit {
        body(...) {
            if(idx == 3) {
                X(qs[3]);
            }
            else {
                X(qs[idx]);
                Controlled SubtractOne(qs[idx..idx], (qs, idx+1));
            }
        }
        adjoint auto;
        controlled auto;
    }

    operation Solve (x : Qubit[], y : Qubit) : Unit {
        body (...) {
            let n = Length(x);
            using(num = Qubit[4]) {
                for(i in 0..n-1) {
                    Controlled AddOne(x[i..i], (num, 0));
                }
                // conditions are
                // (0, 1, 2, 3) bad
                // (0, 3) bad
                // (1, 2) bad
                // (2, 3) bad
                X(num[0]);
                X(num[1]);
                X(num[2]);
                X(num[3]);
                Controlled X(num, y);
                X(num[0]);
                X(num[1]);
                X(num[2]);
                X(num[3]);

                X(num[2]);
                X(num[3]);
                Controlled X(num, y);
                X(num[2]);
                X(num[3]);

                X(num[0]);
                X(num[3]);
                Controlled X(num, y);
                X(num[0]);
                X(num[3]);

                X(num[1]);
                X(num[2]);
                Controlled X(num, y);
                X(num[1]);
                X(num[2]);

                for(i in 0..n-1) {
                    Controlled SubtractOne(x[i..i], (num, 0));
                }
            }
        }
        adjoint auto;
    }

    // Message($"{variable_name_for_debugging}");
    operation RunQsharp() : Bool {
        // goal is (0, 2) are 1/sqrt(2)
        using(qubits = Qubit[4]) {
            H(qubits[0]);
            H(qubits[1]);
            H(qubits[2]);
            Solve(qubits[0..2], qubits[3]);
            DM("win?");
            ResetAll(qubits);
        }
        return true;
    }
}