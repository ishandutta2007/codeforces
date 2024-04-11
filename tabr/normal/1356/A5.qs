namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    
    operation Solve (unitary : (Qubit => Unit is Adj + Ctl)) : Int {
        using (q = Qubit[2]) {
            H(q[1]);
            SWAP(q[0],q[1]);
            Controlled unitary(q[0..0], q[1]);
            SWAP(q[0],q[1]);
            H(q[1]);
            let m = M(q[1]);
            Set(Zero,q[0]);
            Set(Zero,q[1]);
            if(m==One){
                return 1;
            }else{
                return 0;
            }
        }
    }

    operation A (q : Qubit) : Unit is Adj + Ctl {
        Z(q);
    }

    operation B (q : Qubit) : Unit is Adj + Ctl {
        X(q);
        Z(q);
        X(q);
    }

    operation Set (desired : Result, q1 : Qubit) : Unit {
        let current = M(q1);
        if (desired != current) { X(q1); }
    }

    operation Check (cnt : Int) : Int[] {
        mutable res = new Int[4];
        for (i in 0..cnt - 1) {
            let a = Solve(A);
            let b = Solve(B);
            let id = a * 2 - b + 1;
            set res w/= id <- res[id] + 1;
        }
        return res;
    }
}