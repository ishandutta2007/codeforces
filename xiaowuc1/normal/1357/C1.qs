namespace Solution {

    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Measurement;
    open Microsoft.Quantum.Diagnostics;
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
 
    operation Solve (qs : Qubit[]) : Unit {
        using (ancilla = Qubit()) {
            repeat {
                ApplyToEach(H, qs);
                Controlled X(qs, ancilla);
                let res = MResetZ(ancilla);
            }
            until (res == Zero)
            fixup {
                ResetAll(qs);
            }
        }
    }
}