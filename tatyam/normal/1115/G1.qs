namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
 
    operation Solve (qs : Qubit[], bits : Bool[][]) : Unit {
        using(a = Qubit[2]){
        H(a[0]);
        H(a[1]);
        let n = Length(qs);
        for(i in 0 .. n - 1){
            if(bits[0][i]){
                Controlled X(a, qs[i]);
            }
        }
        X(a[0]);
        for(i in 0 .. n - 1){
            if(bits[1][i]){
                Controlled X(a, qs[i]);
            }
        }
        X(a[1]);
        for(i in 0 .. n - 1){
            if(bits[2][i]){
                Controlled X(a, qs[i]);
            }
        }
        X(a[0]);
        for(i in 0 .. n - 1){
            if(bits[3][i]){
                Controlled X(a, qs[i]);
            }
        }
        for(i in 0 .. n - 1){
            if(!bits[0][i]){
                X(qs[i]);
            }
        }
        Controlled X(qs, a[0]);
        for(i in 0 .. n - 1){
            if(!bits[0][i]){
                X(qs[i]);
            }
        }
        for(i in 0 .. n - 1){
            if(!bits[2][i]){
                X(qs[i]);
            }
        }
        Controlled X(qs, a[1]);
        for(i in 0 .. n - 1){
            if(!bits[2][i]){
                X(qs[i]);
            }
        }
        for(i in 0 .. n - 1){
            if(!bits[3][i]){
                X(qs[i]);
            }
        }
        Controlled X(qs, a[0]);
        Controlled X(qs, a[1]);
        for(i in 0 .. n - 1){
            if(!bits[3][i]){
                X(qs[i]);
            }
        }
        }
    }
}