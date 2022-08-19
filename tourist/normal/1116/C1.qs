namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation EvaluateEqualityClauses (x : Qubit[], ancillaRegister : Qubit[]) : Unit {
        body (...) {
            let N = Length(x);
            for (i in 0 .. N - 2) {
                CNOT(x[i], ancillaRegister[i]);
                CNOT(x[i + 1], ancillaRegister[i]);
            }
        }
        adjoint auto;
    }

    operation Solve (x : Qubit[], y : Qubit) : Unit {
        body (...) {
            let N = Length(x);
            using (anc = Qubit[N - 1]) {
                WithA(EvaluateEqualityClauses(x, _), Controlled X(_, y), anc);
            }
        }
        adjoint auto;
    }
}