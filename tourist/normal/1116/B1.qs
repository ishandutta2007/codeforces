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

    operation Build (qs : Qubit[]) : Unit {
        body (...) {
            let theta = ArcSin(1.0 / Sqrt(3.0));
            Ry(2.0 * theta, qs[0]);
            (ControlledOnInt(0, DoIt))(qs[0 .. 0], qs[1 .. 1]);
            (ControlledOnInt(0, X))([qs[0], qs[1]], qs[2]);
            let alpha = 2.0 * PI() / 3.0;
            R1(alpha, qs[1]);
            R1(2.0 * alpha, qs[2]);
        }
        adjoint auto;
    }

    operation Solve (qs : Qubit[]) : Int {
        Adjoint Build(qs);
        if (M(qs[0]) == One) {
            return 1;
        }
        if (M(qs[1]) == One) {
            return 1;
        }
        if (M(qs[2]) == One) {
            return 1;
        }
        return 0;
    }
}