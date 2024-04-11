namespace Solution {
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Extensions.Diagnostics;

    operation DM() : () {
        body {
            DumpMachine("/dev/stdout");
        }
    }

    operation Bell (qs: Qubit[], idx: Int) : () {
        body {
            if (Length(qs) != 2) { fail "BELL TWO"; }
            H(qs[0]);
            CNOT(qs[0],qs[1]);
            if((idx&&&1)!=0) {Z(qs[1]);}
            if((idx&&&2)!=0) {X(qs[1]);}
        }
    }


    operation Solve (qs: Qubit[]) : Int {
        body {
            mutable z = 0;
            CNOT(qs[0],qs[1]);
            H(qs[0]);
            let m1 = M(qs[0]);
            let m2 = M(qs[1]);
            if(m1==One) {set z=z|||1;}
            if(m2==One) {set z=z|||2;}
            return z;
        }
    }



    operation Tester() : () {
        body {
            let BellM=Solve;
            using(qs=Qubit[2]) {
                for(k in 0..3) {
                    Bell(qs,k);
                    let z=BellM(qs);
                    Message($"{k}: {z}");
                    ResetAll(qs);
                }
            }
        }
    }
}