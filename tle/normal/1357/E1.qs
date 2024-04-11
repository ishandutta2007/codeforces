namespace Solution {
    open Microsoft.Quantum.Arithmetic;
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Math;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Diagnostics;

    operation Solve (p : Int, inputRegister : LittleEndian) : Unit is Adj+Ctl {
        for(rep in 1..(p%(PowI(2,Length(inputRegister!))))) {QFTLE(inputRegister);}
    }
}