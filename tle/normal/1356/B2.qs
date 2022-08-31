namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Convert;
    open Microsoft.Quantum.Arithmetic;

    operation Solve (register : LittleEndian) : Unit is Adj+Ctl {
        let n=Length(register!);
        for(i in 0..n-1) {X(register![i]);}
        for(i in 0..n-1) {
            let j=n-1-i;
            (Controlled X)(register![0..j-1],register![j]);
        }
        for(i in 0..n-1) {X(register![i]);}
    }
}