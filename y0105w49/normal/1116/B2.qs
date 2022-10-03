namespace Solution {
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Extensions.Convert;
    open Microsoft.Quantum.Extensions.Diagnostics;
    open Microsoft.Quantum.Extensions.Math;

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
            DumpMachine();
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

                // DumpMachine();

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
                    DumpMachine();
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

    operation Solve1(qs: Qubit[]) : Unit {
        body (...) { }
        controlled auto;
    }
    operation Solve2(qs: Qubit[]) : Unit {
        body (...) {
            let n=2;
            let c=qs[n-1];
            Controlled (ApplyToEachC(H,_))([c], qs[0..n-2]);
            X(c);
            Controlled Solve1([c], qs[0..n-2]);
            X(c);
        }
        controlled auto;
    }
    operation Solve3(qs: Qubit[]) : Unit {
        body (...) {
            let n=3;
            let c=qs[n-1];
            Controlled (ApplyToEachC(H,_))([c], qs[0..n-2]);
            X(c);
            Controlled Solve2([c], qs[0..n-2]);
            X(c);
        }
        controlled auto;
    }
    operation Solve4(qs: Qubit[]) : Unit {
        body (...) {
            let n=4;
            let c=qs[n-1];
            Controlled (ApplyToEachC(H,_))([c], qs[0..n-2]);
            X(c);
            Controlled Solve3([c], qs[0..n-2]);
            X(c);
        }
        controlled auto;
    }
    operation Solve5(qs: Qubit[]) : Unit {
        body (...) {
            let n=5;
            let c=qs[n-1];
            Controlled (ApplyToEachC(H,_))([c], qs[0..n-2]);
            X(c);
            Controlled Solve4([c], qs[0..n-2]);
            X(c);
        }
        controlled auto;
    }
    operation SolveRec(qs: Qubit[]) : Unit {
        body (...) {
            let n=Length(qs);
            if(n==1) { return Solve1(qs); }
            if(n==2) { return Solve2(qs); }
            if(n==3) { return Solve3(qs); }
            if(n==4) { return Solve4(qs); }
            if(n==5) { return Solve5(qs); }
        }
    }


    operation XOp(qs: Qubit[]) : Unit {
        body (...) {
            let n=Length(qs);
            for(i in 1..n-1) {
                CNOT(qs[0],qs[i]);
            }
            H(qs[0]);
            for(i in 1..n-1) {
                CNOT(qs[0],qs[i]);
            }
        }
    }

    operation DumpUnitaryToFiles (N : Int, unitary : (Qubit[] => Unit)) : Unit {
        body (...) {
            let size = 1 <<< N;

            using (qs = Qubit[N]) {
                for (k in 0 .. size - 1) {
                    // Prepare k-th basis vector
                    let binary = BoolArrFromPositiveInt(k, N);

                    //Message($"{k}/{N} = {binary}");
                    // binary is little-endian notation, so the second vector tried has qubit 0 in state 1 and the rest in state 0
                    ApplyPauliFromBitString(PauliX, true, binary, qs);

                    // Apply the operation
                    unitary(qs);

                    // Dump the contents of the k-th column
                    DumpMachine($"DU_{N}_{k}.txt");

                    ResetAll(qs);
                }
            }
        }
    }
    // The operation which is called from C# code
    operation CallDumpUnitary (N : Int) : Unit {
        body (...) {
            // make sure the operation passed to DumpUnitaryToFiles matches the number of qubits set in Driver.cs
            // let unitary = ApplyToEach(I, __);
            let unitary = D6;
            DumpUnitaryToFiles(N, unitary);
        }
    }

    operation Creeper(qs: Qubit[]) : Unit {
        body (...) {
            let q1 = qs[0];
            let q2 = qs[1];
            let q3 = qs[2];

            using(c=Qubit()) {
                UEq(q2,q3,c);

                CCNOT(c,q2,q3);
                Controlled H([c],q2);
                CCNOT(c,q2,q3);
                Controlled H([c],q1);

                X(c);

                X(q1);
                CSWAP(q1,q2,q3);
                Controlled H([c],q1);
                Controlled CSWAP([c],(q1,q2,q3));
                CSWAP(q1,q2,q3);
                X(q1);

                X(c);
                UEq(q2,q3,c);
            }
        }
    }

    function Encode(x: Int, n: Int) : Bool[] {
        mutable z=new Bool[n];
        for(i in 0..n-1) {
            set z[i] = ((x &&& (1<<<i)) != 0);
        }
        return z;
    }
    operation REVq(qs: Qubit[]) : Unit {
        body (...) {
            let n=Length(qs);
            for(x in 0..((1<<<(n-1))-2)) {
                let y=(1<<<n)-2-x;
                using(a=Qubit[2]) {
                    let bx=Encode(x,n);
                    let by=Encode(y,n);

                    for(i in 0..n-1) { if(not bx[i]) { X(qs[i]); } }
                    UAnd(qs,a[0]);
                    for(i in 0..n-1) { if(not bx[i]) { X(qs[i]); } }

                    for(i in 0..n-1) { if(not by[i]) { X(qs[i]); } }
                    UAnd(qs,a[1]);
                    for(i in 0..n-1) { if(not by[i]) { X(qs[i]); } }


                    for(i in 0..n-1) { if(bx[i]) { CNOT(a[0],qs[i]); }}
                    for(i in 0..n-1) { if(by[i]) { CNOT(a[1],qs[i]); }}
                    for(i in 0..n-1) { if(bx[i]) { CNOT(a[1],qs[i]); }}
                    for(i in 0..n-1) { if(by[i]) { CNOT(a[0],qs[i]); }}

                    for(i in 0..n-1) { if(not bx[i]) { X(qs[i]); } }
                    UAnd(qs,a[1]);
                    for(i in 0..n-1) { if(not bx[i]) { X(qs[i]); } }

                    for(i in 0..n-1) { if(not by[i]) { X(qs[i]); } }
                    UAnd(qs,a[0]);
                    for(i in 0..n-1) { if(not by[i]) { X(qs[i]); } }
                }
            }
        }
    }

    operation D5(qs: Qubit[]) : Unit {
        body (...) {
            XOp(qs);
            let n=Length(qs);
            for(i in 0..n-2) { CNOT(qs[n-1],qs[i]); }
            REVq(qs[0..n-2]);
            for(i in 0..n-2) { CNOT(qs[n-1],qs[i]); }
        }
    }


    operation D6(qs: Qubit[]) : Unit {
        body (...) {
            let n=Length(qs);
            using(rs=Qubit[2]) {
                for(y in (1<<<n)-2..-1..0) {
                    for(x in y..y+1) {
                        let bs=Encode(x,n);
                        for(i in 0..n-1) { if(not bs[i]) { X(qs[i]); } }
                        UAnd(qs,rs[x%2]);
                        for(i in 0..n-1) { if(not bs[i]) { X(qs[i]); } }
                    }

                    for(x in y..y+1) {
                        let bs=Encode(x,n);
                        for(i in 0..n-1) { if(bs[i]) { CNOT(rs[x%2],qs[i]); } }
                    }

                    // for(x in (1<<<n)-2..-1..0) {
                    if(true) {
                        let x=y+1;
                        CNOT(rs[x%2],rs[y%2]);
                        Controlled H([rs[y%2]], rs[x%2]);
                        CNOT(rs[x%2],rs[y%2]);
                    }
                    // }

                    for(x in y..y+1) {
                        let bs=Encode(x,n);
                        for(i in 0..n-1) { if(bs[i]) { CNOT(rs[x%2],qs[i]); } }
                    }

                    for(x in y..y+1) {
                        let bs=Encode(x,n);
                        for(i in 0..n-1) { if(not bs[i]) { X(qs[i]); } }
                        UAnd(qs,rs[x%2]);
                        for(i in 0..n-1) { if(not bs[i]) { X(qs[i]); } }
                    }
                }

                // DumpMachine();
            }
        }
    }


    operation B1(qs: Qubit[]) : Int {
        // gen:
        // GenB1(qs[1],qs[2],i%2);
        // X(qs[0]);
        // CNOT(qs[1],qs[0]);
        // CNOT(qs[2],qs[0]);

        body (...) {
            CNOT(qs[1],qs[0]);
            CNOT(qs[2],qs[0]);
            if(M(qs[0]) != One) {
                Message("PANIC! this should be One");
            }
            let q1=qs[1];
            let q2=qs[2];

            let omega = 2.*PI()/3.;
            ApplyDiagonalUnitary([0.,omega,-omega],BigEndian(qs[1..2]));
            // DumpRegister((),[q1,q2]);

            X(q1);
            Controlled H([q1],q2);
            X(q1);
            // DumpRegister((),[q1,q2]);
            if(M(q2) == One) {
                return 1;
            }

            // 0: sqrt(2/3)0 + sqrt(1/3)1
            // 1: sqrt(1/3)0 - sqrt(2/3)1

            // sqrt(2/3)cos(th/2) - sqrt(1/3)sin(th/2) == 0
            // sqrt(2)cos(th/2) = sin(th/2)
            // tan(th/2) == sqrt(2)

            let theta = 2.*ArcTan(Sqrt(2.));
            Ry(theta,q1);
            // DumpRegister((),[q1]);

            if(M(q1) == One) {
                return 0;
            } else {
                return 1;
            }
        }
    }

    operation B2_1(q: Qubit) : Int {
        body (...) {
            let omega=2.*PI()/3.;
            mutable bs=new Bool[3];
            using(rs=Qubit[3]) {
                Rz(PI(),q);
                for(i in 0..2) {
                    H(q);
                    X(q);
                    CNOT(q,rs[i]);
                    X(q);
                    H(q);
                    Rz(omega,q);
                }
                for(i in 2..-1..0) {
                    set bs[i] = M(rs[i])==One;
                }
                // Message($"{bs}");
                ResetAll(rs);
            }
            for(i in 0..2) {
                if(bs[i]) {
                    return i%3;
                }
            }
            Message("PANIC!!");
            return 2;
            // DumpRegister((),[q]);
            // return 3;
        }
    }

    operation B2_2(q: Qubit) : Int {
        body(...) {
            Rz(1.*PI()/6.,q);
            H(q);
            if(M(q)==One) { return 0; }
            return 1;
        }
    }

    operation B2_3(q: Qubit) : Int { // CLONE
        body(...) {
            let th1=ArcSin(Sqrt(1./2. - 1./(2.*Sqrt(3.))));
            let th2=-ArcSin(Sqrt(1./2. - Sqrt(3.)/4.));
            let th3=th1;
            using(a=Qubit[2]) {
                let a1=q;
                let a2=a[0];
                let a3=a[1];
                DumpRegister((),[a1]);

                Ry(2.*th1,a2);
                CNOT(a2,a3);
                Ry(2.*th2,a3);
                CNOT(a3,a2);
                Ry(2.*th3,a2);
                DumpRegister((),[a2,a3]);

                CNOT(a1,a2);
                CNOT(a1,a3);
                CNOT(a2,a1);
                CNOT(a3,a1);
                DumpRegister((),[a1,a2,a3]);

                ResetAll(a);
            }
            H(q);
            if(M(q)==One) { return 0; }
            return 1;
        }
    }

    operation Solve(q: Qubit) : Int {
        body (...) {
            let omega=2.*PI()/3.;
            mutable ans=-1;
            using(r=Qubit()) {
                Rz(PI(),q);
                H(q);
                X(q);
                mutable i=1;
                repeat {
                    Rx(omega,q);
                    Controlled (Ry(0.8,_))([q],r);
                } until(M(r)==One) fixup {
                    set i=i+1;
                    // DumpRegister((),[q,r]);
                }
                X(r);
                set ans=(3-i%3)%3;
            }
            return ans;
            // DumpRegister((),[q]);
            // return 3;
        }
    }

    operation Tester() : Unit {
        body (...) {
            using(q=Qubit()) {
                mutable err=0;
                for(i in 0..999) {
                    H(q);
                    let omega=2.*PI()/3.;
                    Rz(ToDouble(i%3)*omega,q);
                    let ans=Solve(q);
                    if(i%3==ans || i==-1) {
                        // Message($"FAIL! {i%3} {ans}");
                        set err=err+1;
                    }
                    Message($"{i%3} : {ans}   ---   {err}/{i+1}");
                    Reset(q);
                }
                Message($"err count: {err}");
                // DumpMachine();
                // Solve(qs,[[true,true,false],[false,false,false],[true,true,true],[true,false,true]]);
                // Solve(qs);
                // DumpMachine();
            }
        }
    }
}