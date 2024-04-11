namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Math;
    
    operation Solve (t: Double,U : ((Qubit) => Unit is Adj + Ctl)) : Int {
        using(q=Qubit()){
            mutable res=0;
            repeat{
                mutable b=false;
                Reset(q);
                for(i in 0..10){
                    U(q);
                }
                if(M(q)==One){
                    set res = 1;
                    set b = true;
                }
                if(b==false){
                    Reset(q);
                    for(i in 0..10){
                        U(q);
                        Ry(PI() - t, q);
                    }
                    if(M(q)==Zero){
                        set b=true;
                    }
                }
            }until(b)
            fixup{}
            Reset(q);
            return res;
        }
    }

    operation A (q : Qubit) : Unit is Adj + Ctl {
        Rz(1.0,q);
    }

    operation B (q : Qubit) : Unit is Adj + Ctl {
        Ry(1.0,q);
    }

    // operation Set (desired : Result, q1 : Qubit) : Unit {
    //     let current = M(q1);
    //     if (desired != current) { X(q1); }
    // }

    operation Check (cnt : Int) : Int[] {
        mutable res = new Int[4];
        for (i in 0..cnt - 1) {
            let a = Solve(1.0,A);
            let b = Solve(1.0,B);
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
            // set res w/= i <- Solve(Us[i]);
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