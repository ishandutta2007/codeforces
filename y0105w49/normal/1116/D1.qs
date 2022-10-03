namespace Solution {
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Extensions.Convert;
    open Microsoft.Quantum.Extensions.Diagnostics;
    open Microsoft.Quantum.Extensions.Math;

    operation DM() : Unit {
        body (...) {
            DumpMachine();
        }
    }

    operation Bell (qs: Qubit[], idx: Int) : Unit {
        body (...) {
            if (Length(qs) != 2) { fail "BELL TWO"; }
            H(qs[0]);
            CNOT(qs[0],qs[1]);
            if((idx&&&1)!=0) {Z(qs[1]);}
            if((idx&&&2)!=0) {X(qs[1]);}
        }
    }
    operation BellM (qs: Qubit[]) : Int {
        body (...) {
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
    operation UBitSum(x: Qubit[], y: Qubit) : Unit {
        body (...) {
            for (i in 0..Length(x)-1) {
                CNOT(x[i],y);
            }
        }
    }
    operation UConstZero(x: Qubit[], y: Qubit) : Unit {
        body (...) {
        }
    }
    operation UConstOne(x: Qubit[], y: Qubit) : Unit {
        body (...) {
            X(y);
        }
    }
    operation UIndex(x: Qubit[], y: Qubit, k: Int) : Unit {
        body (...) {
            CNOT(x[k],y);
        }
    }

    operation DJ(n: Int, Uf: ((Qubit[],Qubit)=>Unit)) : Bool {
        body (...) {
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

    operation AllStates(qs: Qubit[]) : Unit {
        body (...) {
            for(i in 0..Length(qs)-1) {
                H(qs[i]);
            }
        }
    }

    operation A3(qs: Qubit[],b1: Bool[],b2: Bool[]) : Unit {
        body (...) {
            let n=Length(qs);
            mutable j=-1;
            for(i in 0..n-1) {
                if(b1[i] != b2[i]) {
                    set j=i;
                }
            }

            H(qs[j]);
            for(i in 0..n-1) {
                if(i!=j) {
                    if(b1[i] && b2[i]) {
                        X(qs[i]);
                    } elif(b1[i] || b2[i]) {
                        CNOT(qs[j],qs[i]);
                        if(b2[i]!=b2[j]) {
                            X(qs[i]);
                        }
                    }
                }
            }
        }
    }

    operation D1(x: Qubit[], y: Qubit,b: Int[]) : Unit {
        body (...) {
            for(i in 0..Length(b)-1) {
                if(b[i]==1) {
                    CNOT(x[i],y);
                }
            }
        }
    }
    operation D2(x: Qubit[], y: Qubit,b: Int[]) : Unit {
        body (...) {
            for(i in 0..Length(b)-1) {
                if(b[i]==1) {
                    CNOT(x[i],y);
                } else {
                    X(x[i]);
                    CNOT(x[i],y);
                    X(x[i]);
                }
            }
        }
    }


    operation E1(n: Int, Uf: ((Qubit[],Qubit)=>Unit)) : Int[] {
        body (...) {
        mutable ans=new Int[n];
            using(qs=Qubit[n+1]) {
                let y=qs[n];
                let xs=qs[0..n-1];
                for(i in 0..n-1) { H(xs[i]); }
                X(y); H(y);
                Uf(xs,y);
                for(i in 0..n-1) { H(xs[i]); }
                for(i in 0..n-1) {
                    set ans[i]=0;
                    if(M(xs[i])==One) { set ans[i]=1; }
                }
                ResetAll(qs);
            }
            return ans;
        }
    }

    operation C2(q: Qubit) : Int { body (...) {
        if(Random([0.5,0.5])==1) {
            if(M(q)==One) { return 1; }
            return -1;
        } else {
            H(q);
            if(M(q)==One) { return 0; }
            return -1;
        }
    }}


    operation CSWAP(c: Qubit, x: Qubit, y: Qubit) : Unit { body (...) {
        CCNOT(c,x,y);
        CCNOT(c,y,x);
        CCNOT(c,x,y);
    } controlled auto; adjoint auto; adjoint controlled auto;}
    operation GenW(qs: Qubit[]) : Unit {
        body (...) {
            mutable n=1;
            X(qs[0]);
            for(k in 0..7) {
                if(n<Length(qs)) {
                    using(q=Qubit()) {
                        H(q);
                        for(i in 0..n-1) {
                            CSWAP(q,qs[i],qs[i+n]);
                        }
                        for(i in 0..n-1) {
                            CNOT(qs[i+n],q);
                        }
                    }
                    set n=n*2;
                }
            }
        }
        adjoint (...) {
            mutable n=128;
            for(k in 0..7) {
                if(n<Length(qs)) {
                    using(q=Qubit()) {
                        for(i in 0..n-1) {
                            CNOT(qs[i+n],q);
                        }
                        for(i in 0..n-1) {
                            CSWAP(q,qs[i],qs[i+n]);
                        }
                        H(q);
                    }
                }
                set n=n/2;
            }
            X(qs[0]);
        }
    }


    operation B4(qs: Qubit[]) : Int { body (...) {
        H(qs[1]);
        CNOT(qs[0],qs[1]);
        H(qs[1]);

        H(qs[0]);
        H(qs[1]);
        mutable z=0;
        if(M(qs[0])==One) { set z=z+2; }
        if(M(qs[1])==One) { set z=z+1; }

        if(z==3) { return 0; }
        if(z==0) { return 3; }
        return z;
    }}



    operation Solve_oldcrap(n: Int, Uf: ((Qubit[],Qubit)=>Unit)) : Int[] {
        body (...) {
            mutable ans=new Int[n];
            using(qs=Qubit[n+1]) {
                let y=qs[n];
                let xs=qs[0..n-1];
                for(i in 0..n-1) { X(xs[i]); }
                Uf(xs,y);
                if(M(y)==One) { set ans[0]=1; }
                ResetAll(qs);
            }
            return ans;
        }
    }

    operation C2_opt(q: Qubit) : Int { body (...) {
        mutable z=-1;
        Ry(-PI()/4.,q);
        let theta=ArcCos(Cos(3.*PI()/8.)/Sin(3.*PI()/8.));
        using(rs=Qubit[1]) {
            let r=rs[0];
            X(q); X(r);
            Controlled (Ry(2.*theta,_))([q],r);
            if(M(r)==One) {
                H(q);
                X(q);
                set z=ResultAsInt([M(q)]);
                X(r);
            }
        }
        return z;
    }}

    operation TestC2() : Unit { body (...) {
        mutable gd=new Int[2];
        mutable unk=0;
        let per=1001;
        let its=per*20;
        let op=C2_opt;

        using(qs=Qubit[1]) {
            let q=qs[0];
            for(it in 1..its) {
                let t=Random([0.5,0.5]);
                if(t==1) { H(q); }
                let z=op(q);
                if(z==-1) { set unk=unk+1; }
                else {
                    if(z!=t) { fail "BAD"; }
                    else { set gd[z]=gd[z]+1; }
                }
                Reset(q);

                if(it%per == 0) {
                    Message($"{it} {ToDouble(gd[0])/ToDouble(it)} {ToDouble(gd[1])/ToDouble(it)} {ToDouble(unk)/ToDouble(it)}");
                }
            }
        }
    }}

    operation TesterOld() : Unit {
        body (...) {
            using(q=Qubit()) {
                // let q=qs[0];
                let r1=C2_opt(q);
                Reset(q);
                H(q);
                let r2=C2_opt(q);
                Reset(q);
            }
            TestC2();
        }
    }

    operation UAnd(x: Qubit[], y: Qubit) : Unit {
        body (...) {
            Controlled X(x,y);
        }
        adjoint auto;
    }
    operation UOr(x: Qubit[], y: Qubit) : Unit {
        body (...) {
            for(xx in x) { X(xx); }
            Controlled X(x,y);
            X(y);
            for(xx in x) { X(xx); }
        }
        adjoint auto;
    }
    operation UEq(x1: Qubit, x2: Qubit, y: Qubit) : Unit {
        body (...) {
            UAnd([x1,x2],y);
            X(x1); X(x2);
            UAnd([x1,x2],y);
            X(x1); X(x2);
        }
        adjoint auto;
    }
    operation UIsPal(x: Qubit[], y: Qubit) : Unit {
        body (...) {
            let n=Length(x);
            using(z=Qubit[n/2]) {
                for(i in 0..n/2-1) {
                    let qs=[x[i],x[n-1-i]];
                    UAnd(qs,z[i]);
                    UOr(qs,z[i]);
                    X(z[i]);
                }
                UAnd(z,y);
                for(i in 0..n/2-1) {
                    let qs=[x[i],x[n-1-i]];
                    UAnd(qs,z[i]);
                    UOr(qs,z[i]);
                    X(z[i]);
                }
            }
        }
        adjoint auto;
    }
    operation Reverse(qs: Qubit[]) : Unit {
        body (...) {
            let n=Length(qs);
            for(i in 1..n/2) {
                SWAP(qs[i-1],qs[n-i]);
            }
        }
        controlled auto;
    }

    operation U3(qs: Qubit[]) : Unit {
        body (...) {
            let n=Length(qs);
            let c=qs[n-1];
            X(c);
            Controlled (ApplyToEachC(X,_))([c], qs[0..n-2]);
            X(c);
            Controlled (ApplyToEachC(H,_))([c], qs[0..n-2]);
        }
    }

    operation GenW3_(qs: Qubit[]) : Unit {
        body (...) {
            using(rs = Qubit[4]) {
                repeat {
                    X(rs[0]);
                    using(z = Qubit()) {
                        H(z);
                        CSWAP(z,rs[0],rs[1]);
                        CNOT(rs[1],z);
                        H(z);
                        CSWAP(z,rs[0],rs[2]);
                        CSWAP(z,rs[1],rs[3]);
                        CNOT(rs[2],z);
                        CNOT(rs[3],z);
                    }
                } until (M(rs[3]) == Zero) fixup {
                    X(rs[3]);
                }
                CNOT(rs[1],qs[0]);
                CNOT(rs[2],qs[1]);
                CSWAP(qs[0],rs[0],rs[1]);
                CSWAP(qs[1],rs[0],rs[2]);
                X(rs[0]);
            }
        }
    }

    operation Gen4Ortho(qs: Qubit[], bits: Bool[][]) : Unit {
        body (...) {
            let n=Length(qs);
            using(rs=Qubit[2]) {
                H(rs[0]);
                H(rs[1]);

                X(rs[0]);
                X(rs[1]);
                for(j in 0..n-1) { if(bits[0][j]) { UAnd(rs, qs[j]); } }
                X(rs[0]);
                for(j in 0..n-1) { if(bits[1][j]) { UAnd(rs, qs[j]); } }
                X(rs[0]);
                X(rs[1]);
                for(j in 0..n-1) { if(bits[2][j]) { UAnd(rs, qs[j]); } }
                X(rs[0]);
                for(j in 0..n-1) { if(bits[3][j]) { UAnd(rs, qs[j]); } }

                // DM();

                for(j in 0..n-1) { if(not bits[0][j]) { X(qs[j]); } }
                for(j in 0..n-1) { if(not bits[0][j]) { X(qs[j]); } }

                for(j in 0..n-1) { if(not bits[1][j]) { X(qs[j]); } }
                UAnd(qs,rs[0]);
                for(j in 0..n-1) { if(not bits[1][j]) { X(qs[j]); } }

                for(j in 0..n-1) { if(not bits[2][j]) { X(qs[j]); } }
                UAnd(qs,rs[1]);
                for(j in 0..n-1) { if(not bits[2][j]) { X(qs[j]); } }

                for(j in 0..n-1) { if(not bits[3][j]) { X(qs[j]); } }
                UAnd(qs,rs[0]);
                UAnd(qs,rs[1]);
                for(j in 0..n-1) { if(not bits[3][j]) { X(qs[j]); } }
            }
        }
    }

    operation IsAlt(x: Qubit[], y: Qubit) : Unit {
        body (...) {
            let n=Length(x);
            using(rs=Qubit[n-1]) {
                for(i in 0..n-2) {
                    UAnd(x[i..i+1], rs[i]);
                    X(x[i]); X(x[i+1]);
                    UAnd(x[i..i+1], rs[i]);
                    X(x[i]); X(x[i+1]);
                }
                UOr(rs,y);
                X(y);
                for(i in 0..n-2) {
                    UAnd(x[i..i+1], rs[i]);
                    X(x[i]); X(x[i+1]);
                    UAnd(x[i..i+1], rs[i]);
                    X(x[i]); X(x[i+1]);
                }
            }
        }
        adjoint auto;
    }

    operation IsPeriodic(x: Qubit[], y: Qubit) : Unit {
        body (...) {
            let n=Length(x);
            using(rs=Qubit[n-(n+1)/2]) {
                for(p in (n+1)/2..n-1) {
                    using(qs=Qubit[n-p]) {
                        for(i in 0..n-p-1) {
                            UEq(x[i],x[i+p],qs[i]);
                        }
                        UAnd(qs,rs[p-(n+1)/2]);
                        for(i in 0..n-p-1) {
                            UEq(x[i],x[i+p],qs[i]);
                        }
                    }
                }
                UOr(rs,y);
                for(p in (n+1)/2..n-1) {
                    using(qs=Qubit[n-p]) {
                        for(i in 0..n-p-1) {
                            UEq(x[i],x[i+p],qs[i]);
                        }
                        UAnd(qs,rs[p-(n+1)/2]);
                        for(i in 0..n-p-1) {
                            UEq(x[i],x[i+p],qs[i]);
                        }
                    }
                }
            }
        }
        adjoint auto;
    }

    operation ROT(x: Qubit[]) : Unit {
        body (...) {
            let n = Length(x);
            using(y=Qubit()) {
                SWAP(x[0],y);
                for(i in 1..n-1) {
                    SWAP(x[i],x[i-1]);
                }
                SWAP(y,x[n-1]);
            }
        }
        adjoint auto;
        controlled auto;
        adjoint controlled auto;
    }
    operation ROT3(x1: Qubit, x2: Qubit, x3: Qubit) : Unit {
        body (...) {
            SWAP(x1,x2);
            SWAP(x2,x3);
        }
        adjoint auto;
        controlled auto;
        adjoint controlled auto;
    }
    operation Divs3(x: Qubit[], y: Qubit) : Unit {
        body (...) {
            using(zs=Qubit[3]) {
                let z0=zs[0];
                let z1=zs[1];
                let z2=zs[2];
                X(z0);
                for(q in x) {
                    CSWAP(q,z0,z1);
                    CSWAP(q,z1,z2);
                }
                CNOT(z0,y);
                for(q in x) {
                    CSWAP(q,z1,z2);
                    CSWAP(q,z0,z1);
                }
                X(z0);
            }
        }
        adjoint auto;
    }

    operation GenW3(qs: Qubit[]) : Unit {
        body (...) {
            using(rs = Qubit[4]) {
                repeat {
                    X(rs[0]);
                    using(z = Qubit()) {
                        H(z);
                        CSWAP(z,rs[0],rs[1]);
                        CNOT(rs[1],z);
                        H(z);
                        CSWAP(z,rs[0],rs[2]);
                        CSWAP(z,rs[1],rs[3]);
                        CNOT(rs[2],z);
                        CNOT(rs[3],z);
                    }
                } until (M(rs[3]) == Zero) fixup {
                    X(rs[3]);
                }
                SWAP(rs[0],qs[0]);
                SWAP(rs[1],qs[1]);
                SWAP(rs[2],qs[2]);
            }
        }
    }

    operation GenW3Fake(rs: Qubit[]) : Unit {
        body (...) {
            X(rs[0]);
            using(z = Qubit()) {
                H(z);
                CSWAP(z,rs[0],rs[1]);
                CNOT(rs[1],z);
                H(z);
                CSWAP(z,rs[0],rs[2]);
                CSWAP(z,rs[1],rs[3]);
                CNOT(rs[2],z);
                CNOT(rs[3],z);
            }
            // CNOT(rs[1],qs[0]);
            // CNOT(rs[2],qs[1]);
            // CSWAP(qs[0],rs[0],rs[1]);
            // CSWAP(qs[1],rs[0],rs[2]);
            // X(rs[0]);
        }
        adjoint auto;
    }
    operation GenB1(q1: Qubit, q2: Qubit,b: Int) : Unit {
        body (...) {
            GenW3_([q1,q2]);
            CNOT(q2,q1);
            Controlled (Rz(2.*PI()/3.,_))([q1],q2);
            CNOT(q2,q1);
            using(r=Qubit()) {
                UOr([q1,q2],r);
                Controlled Z([r], q1);
                Controlled Z([r], q2);
                UOr([q1,q2],r);
            }
            if(b==1) { SWAP(q1,q2); }
        }
    }
    operation GenB1APure(q1: Qubit, q2: Qubit) : Unit {
        body (...) {
            using(r=Qubit[4]) {
                GenW3Fake(r);
                CNOT(r[3],q2);
                CNOT(r[3],q1);
                CNOT(r[2],q2);
                CNOT(r[1],q1);

                UAnd([q1,q2],r[3]);
                X(q1);
                UAnd([q1,q2],r[2]);
                X(q2);
                UAnd([q1,q2],r[0]);
                X(q1);
                UAnd([q1,q2],r[1]);
                X(q2);
            }
            CNOT(q2,q1);
            Controlled (Rz(2.*PI()/3.,_))([q1],q2);
            CNOT(q2,q1);
        }
        adjoint auto;
    }

    operation Solve_(q1: Qubit, q2: Qubit) : Int {
        body (...) {
            using(r=Qubit()) {
                UOr([q1,q2],r);
                Controlled Z([r], q1);
                Controlled Z([r], q2);
                UOr([q1,q2],r);
            }
            CNOT(q2,q1);
            Controlled (Rz(2.*PI()/3.,_))([q1],q2);
            CNOT(q2,q1);

            using(q3=Qubit()) {
                UOr([q1,q2],q3);
                X(q3);
                using(z = Qubit()) {
                    CNOT(q3,z);
                    // CSWAP(z,q2,q4);
                    // CNOT(z,q2);
                    CSWAP(z,q1,q3);
                    H(z);
                    CNOT(q2,z);
                    CSWAP(z,q1,q2);
                    H(z);
                    DM();
                }
            }
            return 2;
        }
    }

    operation Solve__(qs: Qubit[]) : Int {
        body (...) {
            CNOT(qs[1],qs[0]);
            CNOT(qs[2],qs[0]);
            if(M(qs[0]) != One) {
                Message("PANIC! this should be One");
            }

            return Solve_(qs[1],qs[2]);
        }
    }

    operation Solve(qs: Qubit[]) : Unit {
        body (...) {
            H(qs[0]);
        }
    }


    operation Tester() : Unit {
        body (...) {
            using(qs=Qubit[2]) {
                for(i in 1..6) {
                    GenB1(qs[0],qs[1],i%2);
                    Message($"{i%2} : {Solve_(qs[0],qs[1])}");
                    ResetAll(qs);
                }
                // DM();
                // Solve(qs,[[true,true,false],[false,false,false],[true,true,true],[true,false,true]]);
                // Solve(qs);
                // DM();
            }
        }
    }
}