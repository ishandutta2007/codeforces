namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    
    operation Solve (U : (Qubit => Unit is Adj + Ctl)) : Int {
        using(q=Qubit()){
            U(q);
            X(q);
            U(q);
            let m = M(q);
            Reset(q);
            if(m==Zero){
                return 0;
            }else{
                return 1;
            }
        }
    }

    operation A (q : Qubit) : Unit is Adj + Ctl {
        H(q);
    }

    operation B (q : Qubit) : Unit is Adj + Ctl {
        X(q);
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