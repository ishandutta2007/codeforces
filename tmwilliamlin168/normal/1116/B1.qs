namespace Solution
{
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Extensions.Math;

    operation Solve (x : Qubit[]) : Int {
        R1(2.0*PI()/3.0, x[1]);
        R1(4.0*PI()/3.0, x[2]);
        X(x[0]);
        X(x[1]);
        Controlled X(x[0..1], x[2]);
        X(x[1]);
        Controlled H([x[0]], x[1]);
        X(x[0]);
        Ry(-1.23095942, x[0]);
        if(M(x[0])==One||M(x[1])==One) {
            return 0;
        }
        return 1;
    }
}