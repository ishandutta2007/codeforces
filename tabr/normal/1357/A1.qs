namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    
    operation Solve (U : (Qubit[] => Unit is Adj + Ctl)) : Int {
        using(qs=Qubit[2]){
            X(qs[0]);
            X(qs[1]);
            U(qs);
            let m=M(qs[0]);
            ResetAll(qs);
            if(m==Zero){
                return 1;
            }else{
                return 0;
            }
        }
    }

    operation A (q : Qubit[]) : Unit is Adj + Ctl {
        CNOT(q[0],q[1]);
    }

    operation B (q : Qubit[]) : Unit is Adj + Ctl {
        CNOT(q[1],q[0]);
    }

    // operation Set (desired : Result, q1 : Qubit) : Unit {
    //     let current = M(q1);
    //     if (desired != current) { X(q1); }
    // }

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

    operation All (cnt : Int) : Int[] {
        let Us = [A, B];
        let n = Length(Us);
        mutable res = new Int[n];
        for (i in 0..n - 1) {
            set res w/= i <- Solve(Us[i]);
        }
        return res;
    }

    // operation Solo (cnt : Int, num : Int, U : (Qubit => Unit is Adj + Ctl)) : Int[] {
    //     mutable res = new Int[num];
    //     for (i in 0..cnt - 1) {
    //         let j = Solve(U);
    //         set res w/= j <- res[j] + 1;
    //     }
    //     return res;
    // }
}