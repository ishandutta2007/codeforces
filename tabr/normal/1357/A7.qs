namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Math;
    
    operation Solve (U : ((Qubit) => Unit is Adj + Ctl)) : Int {
        using(a=Qubit[2]){
            H(a[0]);
            Controlled H(a[0..0],a[1]);
            Controlled U(a[0..0],a[1]);
            CNOT(a[0],a[1]);
            Controlled U(a[0..0],a[1]);
            Controlled H(a[0..0],a[1]);
            H(a[0]);
            if(M(a[0])==One){ // 0 or 2
                ResetAll(a);
                H(a[0]);
                CNOT(a[0],a[1]);
                Controlled U(a[0..0],a[1]);
                S(a[0]);
                H(a[0]);
                let m=M(a[0]);
                ResetAll(a);
                if(m==Zero){
                    return 0;
                }else{
                    return 2;
                }
            }else{ // 1 or 3
                ResetAll(a);
                H(a[0]);
                CNOT(a[0],a[1]);
                Controlled U(a[0..0],a[1]);
                H(a[0]);
                let m=M(a[0]);
                ResetAll(a);
                if(m==One){
                    return 3;
                }else{
                    return 1;
                }
            }
        }
    }

    operation A (q : Qubit) : Unit is Adj + Ctl {
        Y(q);
    }
 
    operation B (q : Qubit) : Unit is Adj + Ctl {
        Z(q);
        X(q);
        Ry(2.0*PI(),q);
    }
 
    operation C (q : Qubit) : Unit is Adj + Ctl {
        Y(q);
        Ry(2.0*PI(),q);
    }
 
    operation D (q : Qubit) : Unit is Adj + Ctl {
        Z(q);
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