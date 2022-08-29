namespace Solution {
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Intrinsic;

    operation Solve (x : Qubit[], y : Qubit) : Unit {
        Controlled X([x[0], x[1]], y);
        Controlled X([x[1], x[2]], y);
        Controlled X([x[2], x[0]], y);
    }
}