namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Math;
    
    operation Solve (U : ((Qubit) => Unit is Adj + Ctl)) : Int {
        mutable res=0;
        using(a=Qubit[2]){
            H(a[0]);
            CNOT(a[0],a[1]);
            H(a[1]);
            U(a[1]);
            H(a[1]);
            CNOT(a[0],a[1]);
            H(a[0]);
            let s=M(a[0]);
            let t=M(a[1]);
            ResetAll(a);
            if(s==Zero){
                if(t==Zero){
                    set res=0;
                }else{
                    set res=3;
                }
            }else{
                if(t==Zero){
                    set res=1;
                }else{
                    set res=2;
                }
            }
        }
        return res;
    }

    operation A (q : Qubit) : Unit is Adj + Ctl {
    }
 
    operation B (q : Qubit) : Unit is Adj + Ctl {
        X(q);
    }
 
    operation C (q : Qubit) : Unit is Adj + Ctl {
        Y(q);
    }
 
    operation D (q : Qubit) : Unit is Adj + Ctl {
        Z(q);
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
        let Us = [A, B, C, D];
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