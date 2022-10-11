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

    operation RotateQubit(q: Qubit, theta: Double) : Unit {
        body(...) {
            Ry(theta, q);
        }
        adjoint auto;
        controlled auto;
    }

    operation RecursiveOne(qs: Qubit[], b1: Bool[]) : Unit {
        body(...) {
            XorOracle(qs, b1);
        }
        controlled auto;
    }

    operation RecursiveTwo(qs: Qubit[], b1: Bool[], b2: Bool[]) : Unit {
        body(...) {
            using(anc = Qubit[1]) {
                let theta = ArcSin(1.0/Sqrt(2.0));
                RotateQubit(anc[0], 2.*theta);
                // zero
                X(anc[0]);
                Controlled RecursiveOne(anc, (qs, b2));
                X(anc[0]);
                // one
                Controlled XorOracle(anc, (qs, b1));
                for(i in 0..Length(qs)-1) {
                    if(not b1[i]) {
                        X(qs[i]);
                    }
                }
                AndOracle(qs, anc[0]);
                for(i in 0..Length(qs)-1) {
                    if(not b1[i]) {
                        X(qs[i]);
                    }
                }
            }    
        }
        controlled auto;
    }

    operation RecursiveThree(qs: Qubit[], b1: Bool[], b2: Bool[], b3: Bool[]) : Unit {
        body(...) {
            using(anc = Qubit[1]) {
                let theta = ArcSin(1.0/Sqrt(3.0));
                RotateQubit(anc[0], 2.*theta);
                // zero
                X(anc[0]);
                Controlled RecursiveTwo(anc, (qs, b2, b3));
                X(anc[0]);
                // one
                Controlled XorOracle(anc, (qs, b1));
                for(i in 0..Length(qs)-1) {
                    if(not b1[i]) {
                        X(qs[i]);
                    }
                }
                AndOracle(qs, anc[0]);
                for(i in 0..Length(qs)-1) {
                    if(not b1[i]) {
                        X(qs[i]);
                    }
                }
            }    
        }
        controlled auto;
    }

    operation RecursiveFour(qs: Qubit[], b1: Bool[], b2: Bool[], b3: Bool[], b4: Bool[]) : Unit {
        using(anc = Qubit[1]) {
            let theta = ArcSin(0.5);    
            RotateQubit(anc[0], 2.*theta);
            // zero
            X(anc[0]);
            Controlled RecursiveThree(anc, (qs, b2, b3, b4));
            X(anc[0]);
            // one
            Controlled XorOracle(anc, (qs, b1));
            for(i in 0..Length(qs)-1) {
                if(not b1[i]) {
                    X(qs[i]);
                }
            }
            AndOracle(qs, anc[0]);
            for(i in 0..Length(qs)-1) {
                if(not b1[i]) {
                    X(qs[i]);
                }
            }
        }
    }

    operation Solve (qs : Qubit[], bits : Bool[][]) : Unit {
        body (...) {
            RecursiveFour(qs, bits[0], bits[1], bits[2], bits[3]);
        }
    }

    // Message($"{variable_name_for_debugging}");
    operation RunQsharp() : Bool {
        // goal is (0, 2) are 1/sqrt(2)
        using(qubits = Qubit[3]) {
            let g = [
                [true, true, true],
                [false, true, false],
                [true, false, true],
                [false, false, false]
            ];
            Solve(qubits, g);
            DM("win?");
            ResetAll(qubits);
        }
        return true;
    }
}