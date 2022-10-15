namespace Solution
{
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Primitive;

    operation sumMIT (x : Qubit[], prodakcin : Qubit[]) : Unit {
        body (...) {
            X(prodakcin[0]);
            X(prodakcin[1]);
            for(xi in x) {
                Controlled X([xi, prodakcin[1]], prodakcin[0]);
                Controlled X([xi, prodakcin[0]], prodakcin[1]);
            }
        }
        adjoint auto;
    }

    operation Solve (x : Qubit[], y : Qubit) : Unit {
        body (...) {
            //how is frodakcin sucha prodakcin
            using(prodakcin = Qubit[2]) {
                WithA(sumMIT(x, _), Controlled X(_, y), prodakcin);
            }
        }
        adjoint auto;
    }
}