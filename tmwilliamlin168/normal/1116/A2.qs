namespace Solution {
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Extensions.Convert;
    open Microsoft.Quantum.Extensions.Math;

    function cnt (a : Bool, b : Bool, c : Bool, d : Bool) : Double {
        mutable e=0.0;
        if(a) {
            set e=e+1.0;
        }
        if(b) {
            set e=e+1.0;
        }
        if(c) {
            set e=e+1.0;
        }
        if(d) {
            set e=e+1.0;
        }
        return e;
    }

    operation benqisgod (x : Qubit[], bits : Bool[][], i : Int, a : Bool, b : Bool, c : Bool, d : Bool) : Unit {
        // Message(ToStringI(i)+" "+ToStringB(a)+" "+ToStringB(b)+" "+ToStringB(c)+" "+ToStringB(d));
        if(i>=Length(x) || not a && not b && not c && not d) {
            return ();
        }
        let cnt1=cnt(a&&bits[0][i], b&&bits[1][i], c&&bits[2][i], d&&bits[3][i]);
        let cnt2=cnt(a, b, c, d);
        // if(cnt1==4.0) {
            // Message(ToStringD(ArcSin(Sqrt(cnt1/cnt2))*2.0));
        // }
        Controlled Ry(x[0..i-1], (ArcSin(Sqrt(cnt1/cnt2))*2.0, x[i]));
        X(x[i]);
        // Controlled X(x[0..i-1], x[i]);
        benqisgod(x, bits, i+1, a&&not bits[0][i], b&&not bits[1][i], c&&not bits[2][i], d&&not bits[3][i]);
        X(x[i]);
        // Controlled X(x[0..i-1], x[i]);
        benqisgod(x, bits, i+1, a&&bits[0][i], b&&bits[1][i], c&&bits[2][i], d&&bits[3][i]);
    }

    operation Solve (x : Qubit[], bits : Bool[][]) : Unit {
        benqisgod(x, bits, 0, true, true, true, true);
    }
}