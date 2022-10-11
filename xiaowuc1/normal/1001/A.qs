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

    operation Solve (q : Qubit, sign : Int) : Unit {
        if(sign == 1) {
            H(q);
        }
        else {
            X(q);
            H(q);
        }
    }

    operation RunQsharp() : Bool {
        using(qubit = Qubit[1]) {
            Set(Zero, qubit[0]);
            Solve(qubit[0], 1);
            DM();
            Set(Zero, qubit[0]);
            Solve(qubit[0], -1);
            DM();
            Set(Zero, qubit[0]);
        }
        return true;
    }
}