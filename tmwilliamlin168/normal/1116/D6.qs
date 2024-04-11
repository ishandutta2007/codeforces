namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Extensions.Math;

    operation sub (x : Qubit[], n : Int, a : Int) : Unit {
        body (...) {
            for(i in a..n-1) {
                Controlled X(x[a..i-1], x[i]);
            }
        }
        controlled auto;
    }

    operation add (x : Qubit[], n : Int, a : Int) : Unit {
        body (...) {
            ApplyToEachC(X, x[0..n-1]);
            sub(x, n, a);
            ApplyToEachC(X, x[0..n-1]);
        }
        controlled auto;
    }

    operation swap1 (x : Qubit, y : Qubit) : Unit {
        body(...) {
            CNOT(x, y);
            Controlled Ry([y], (PI()/2.0, x));
            CNOT(x, y);
        }
        controlled auto;
    }

    operation benericqwei(x : Qubit[], n : Int) : Unit {
        body(...) {
            if(n>1) {
                Controlled benericqwei([x[n-1]], (x, n-1));
                add(x, n, n-1);
                sub(x, n, 0);
                Controlled Ry(x[1..n-1], (PI()/2.0, x[0]));
                sub(x, n, n-1);
                add(x, n, 0);
                X(x[n-1]);
                Controlled benericqwei([x[n-1]], (x, n-1));
                X(x[n-1]);
            } else {
                H(x[0]);
            }
        }
        controlled auto;
    }

    operation Solve (x : Qubit[]) : Unit {
        benericqwei(x, Length(x));
    }
}