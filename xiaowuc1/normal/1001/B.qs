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

    operation Solve(qs : Qubit[], index : Int) : Unit {
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
        using(qubit = Qubit[2]) {
            for(i in 0..0) {
                Set(Zero, qubit[0]);
                Set(Zero, qubit[1]);
                Solve(qubit, 3);
                DM();
            }
            ResetAll(qubit);
        }
        return true;
    }
}