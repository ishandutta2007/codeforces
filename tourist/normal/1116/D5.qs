namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation EvaluateEqualityClauses (x : Qubit[], ancillaRegister : Qubit[]) : Unit {
        body (...) {
            CNOT(x[1], ancillaRegister[0]);
            CNOT(x[2], ancillaRegister[0]);
            X(ancillaRegister[0]);
        }
        adjoint auto;
    }

    operation DoIt (x : Qubit[]) : Unit {
        body (...) {
            CNOT(x[1], x[2]);
            H(x[1]);
            CNOT(x[1], x[2]);
        }
        adjoint auto;
        controlled auto;
        adjoint controlled auto;
    }

    operation Solve (qs : Qubit[]) : Unit {
        // 01234567
        Controlled X([qs[1]], qs[0]);
        // 01324576
        Controlled X([qs[2]], qs[0]);
        // 01325467
        Controlled X([qs[0]], qs[1]);
        // 03127465
        Controlled X([qs[0]], qs[2]);
        // 07523461
        Controlled X([qs[2]], qs[0]);
        // 06423571
        using (anc = Qubit[1]) {
            WithA(EvaluateEqualityClauses(qs, _), Controlled DoIt(_, qs), anc);
        }
        H(qs[0]);
    }
}