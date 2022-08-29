namespace Solution {
    open Microsoft.Quantum.Arithmetic;
    open Microsoft.Quantum.Intrinsic;
 
    operation Solve (register : LittleEndian) : Unit is Adj+Ctl {
        let q = register!;
        for (i in Length(q) - 1 .. -1 .. 1) {
            Controlled X(q[0 .. i - 1], q[i]);
        }
        X(q[0]);
    }
}