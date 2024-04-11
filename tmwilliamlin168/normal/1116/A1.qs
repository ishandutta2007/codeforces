
 namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : Unit {
        Ry(1.23095942, qs[0]);
        X(qs[0]);
        Controlled H([qs[0]], qs[1]);
        X(qs[0]);
    }
}