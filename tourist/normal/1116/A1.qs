namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Extensions.Convert;
    open Microsoft.Quantum.Extensions.Math;
    
    operation DoIt (qs : Qubit[]) : Unit {
        body (...) {
            let gamma = ArcSin(1.0 / Sqrt(2.0));
            Ry(2.0 * gamma, qs[0]);
        }
        adjoint invert;
        controlled distribute;
        controlled adjoint distribute;
    }

    operation Solve (qs : Qubit[]) : Unit {
        let theta = ArcSin(1.0 / Sqrt(3.0));
        Ry(2.0 * theta, qs[0]);
        (ControlledOnInt(0, DoIt))(qs[0 .. 0], qs[1 .. 1]);
    }
}