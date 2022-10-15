namespace Solution {
  open Microsoft.Quantum.Canon;
  open Microsoft.Quantum.Arithmetic;
  
  operation Solve(p: Int, inputRegister: LittleEndian): Unit is Adj+Ctl {
    for (i in 0 .. p % 4 - 1) {
      QFTLE(inputRegister);
    }
  }
}