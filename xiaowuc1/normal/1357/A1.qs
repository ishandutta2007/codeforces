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
 
    operation Solve (unitary : (Qubit[] => Unit is Adj+Ctl)) : Int {
        // your code here
        mutable ret = 0;
        using(q = Qubit[2]) {
            X(q[0]);
            unitary(q);
            if(M(q[1]) == Zero) {
                set ret = 1;
            }
            ResetAll(q);
        }
        return ret;
    }
}