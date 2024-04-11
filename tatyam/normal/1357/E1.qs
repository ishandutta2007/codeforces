namespace Solution {
    open Microsoft.Quantum.Arithmetic;
    open Microsoft.Quantum.Arrays;
    open Microsoft.Quantum.Bitwise;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Convert;
    open Microsoft.Quantum.Diagnostics;
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Math;
    
    
    operation Solve (p : Int, inputRegister : LittleEndian) : Unit is Adj+Ctl {
        for (i in 1 .. p % 4) {
            QFTLE(inputRegister);
        }
    }
}