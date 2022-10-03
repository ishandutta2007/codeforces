namespace Solution {

    open Microsoft.Quantum.Arithmetic;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Diagnostics;
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Math;

    operation A5(unitary: (Qubit => Unit is Adj+Ctl)) : Int {
        body(...) {
            using(qs=Qubit[2]) {
                let q=qs[0];
                let r=qs[1];
                H(q);
                CNOT(q,r);
                (Controlled unitary)([q],r);
                CZ(q,r);
                CNOT(q,r);
                H(q);
                if (M(q)==One) {
                    ResetAll(qs);
                    return 1;
                } else {
                    ResetAll(qs);
                    return 0;
                }
            }
        }
    }

    operation SWP(x: Qubit, y: Qubit) : Unit is Adj+Ctl {
        body (...) {
            CNOT(x,y);
            CNOT(y,x);
            CNOT(x,y);
        }
    }
    operation GenW3(qs: Qubit[]) : Unit {
        body (...) {
            using(rs = Qubit[4]) {
                repeat {
                    X(rs[0]);
                    using(z = Qubit()) {
                        H(z);
                        (Controlled SWP)([z],(rs[0],rs[1]));
                        CNOT(rs[1],z);
                        H(z);
                        (Controlled SWP)([z],(rs[0],rs[2]));
                        (Controlled SWP)([z],(rs[1],rs[3]));
                        CNOT(rs[2],z);
                        CNOT(rs[3],z);
                    }
                } until (M(rs[3]) == Zero) fixup {
                    X(rs[3]);
                }
                SWP(rs[0],qs[0]);
                SWP(rs[1],qs[1]);
                SWP(rs[2],qs[2]);
            }
        }
    }
    operation ProbC(qs:Qubit[]) : Unit {
        body(...) {
            using(rs=Qubit[3]) {
                GenW3(rs);
                SWP(rs[1],qs[0]);
                SWP(rs[2],qs[1]);
                CNOT(rs[0],qs[0]);
                CNOT(rs[0],qs[1]);
                CCNOT(qs[0],qs[1],rs[0]);
            }
        }
    }


    operation Incr(register:LittleEndian) : Unit is Adj+Ctl {
        body(...) {
            let qs=register!;
            if(Length(qs)>0) {
                (Controlled Incr)([qs[0]],LittleEndian(qs[1..Length(qs)-1]));
                X(qs[0]);
            }
        }
    }
    operation Decr(register:LittleEndian) : Unit is Adj+Ctl {
        body(...) {
            (Adjoint Incr)(register);
        }
    }

    operation Solve(unitary: ((Double,Qubit)=> Unit is Adj+Ctl)) : Int {
        body(...) {
            using(qs=Qubit[2]) {
                let q=qs[0];
                let r=qs[1];
                H(q);
                CNOT(q,r);
                (Controlled (unitary(PI()*2.,_)))([q],r);
                // (Controlled (Rz(PI(),_)))([q],r);
                CNOT(q,r);
                H(q);
                if(M(q)==One) {
                    X(q);
                    return 0;
                } else {
                    return 1;
                }
            }
        }
    }




    operation mZ(q: Qubit) : Unit is Adj+Ctl {
        body(...) {
            X(q);
            Z(q);
            X(q);
        }
    }
    operation cnot0(qs: Qubit[]) : Unit is Adj+Ctl { body(...) {
        CNOT(qs[0],qs[1]);
        }}
    operation cnot1(qs: Qubit[]) : Unit is Adj+Ctl { body(...) {
        CNOT(qs[1],qs[0]);
        }}
    operation swp(qs: Qubit[]) : Unit is Adj+Ctl { body(...) {
        SWAP(qs[0],qs[1]);
        }}
    operation ident(qs: Qubit[]) : Unit is Adj+Ctl { body(...) {

        }}
    operation Tester() : Unit {
        body(...) {
            Message("qqz");
            for(i in 1..1) {
                Message($"{Solve(Rz)} - {Solve(R1)}");
            }
            // for(i in 1..4) {
            //     // Message($"{Solve(ApplyPauli([PauliI,PauliX],_))} - {Solve(ApplyToFirstTwoQubitsCA(CNOT,_))}");
            //     Message($"{A5(Z)} - {A5(mZ)}");
            // }
            // using(qs=Qubit[3]) {
            //     for(i in 1..8) {
            //         Decr(LittleEndian(qs));
            //         DumpMachine(());
            //     }
            // }
        }
    }

    operation Main() : Unit {
        body(...) {
            Tester();
        }
    }
}