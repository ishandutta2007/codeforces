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
    operation BellM (qs: Qubit[]) : Int {
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
    operation UBitSum(x: Qubit[], y: Qubit) : () {
        body {
            for(i in 0..Length(x)-1) {
                CNOT(x[i],y);
            }
        }
    }
    operation UConstZero(x: Qubit[], y: Qubit) : () {
        body {
        }
    }
    operation UConstOne(x: Qubit[], y: Qubit) : () {
        body {
            X(y);
        }
    }
    operation UIndex(x: Qubit[], y: Qubit, k: Int) : () {
        body {
            CNOT(x[k],y);
        }
    }

    operation DJ(n: Int, Uf: ((Qubit[],Qubit)=>())) : Bool {
        body {
            mutable ans=true;
            using(qs=Qubit[n+1]) {
                let y=qs[n];
                let xs=qs[0..n-1];
                for(i in 0..n-1) { H(xs[i]); }
                X(y); H(y);
                Uf(xs,y);
                for(i in 0..n-1) { H(xs[i]); }
                for(i in 0..n-1) {
                    let z=M(xs[i]);
                    if(z==One) { set ans=false; }
                }
                ResetAll(qs);
            }
            return ans;
        }
    }

    operation AllStates(qs: Qubit[]) : () {
        body {
            for(i in 0..Length(qs)-1) {
                H(qs[i]);
            }
        }
    }

    operation Solve(qs: Qubit[],bits: Bool[]) : () {
        body {
            let qq=qs[0];
            H(qq);
            for(i in 1..Length(bits)-1) {
                if(bits[i]) {
                    CNOT(qq,qs[i]);
                }
            }
        }
    }

    operation Tester() : () {
        body {
            using(qs2=Qubit[2]) {
                Solve(qs2,[true;false]);
                DM();ResetAll(qs2);
            }
            let uf=UIndex(_,_,4);
            let z5=DJ(5,uf);
            let z6=DJ(6,uf);
            Message($"{z5} {z6}");
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