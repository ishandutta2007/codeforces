namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Extensions.Math;

    operation Solve (qs : Qubit[]) : Unit {
        Ry(1.9106332362490185960979260926251299679279327392578125,qs[0]);
        Controlled H([qs[0]],qs[1]);
        X(qs[0]);
    }
}