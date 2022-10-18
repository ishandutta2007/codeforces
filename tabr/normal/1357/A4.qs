namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Math;
    
    operation Solve (U : ((Double, Qubit) => Unit is Adj + Ctl)) : Int {
        using(q=Qubit[2]){
            H(q[0]);
            H(q[1]);
            Controlled U(q[0..0],(PI()*2.0,q[1]));
            SWAP(q[0],q[1]);
            H(q[1]);
            let m=M(q[1]);
            ResetAll(q);
            if(m==One){
                return 0;
            }else{
                return 1;
            }
        }
    }

    operation A (a:Double, q : Qubit) : Unit is Adj + Ctl {
        Rz(a,q);
    }

    operation B (a:Double, q : Qubit) : Unit is Adj + Ctl {
        R1(a,q);
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