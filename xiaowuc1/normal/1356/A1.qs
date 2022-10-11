namespace Solution {

    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Intrinsic;
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
 
    operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        // your code here
        mutable ret = 0;
        using(qubit = Qubit[1]) {
            Set(Zero, qubit[0]);
            unitary(qubit[0]);
            if(M(qubit[0]) != Zero) {
                set ret = 1;
            }
            Reset(qubit[0]);
        }
        return ret;
    }
}