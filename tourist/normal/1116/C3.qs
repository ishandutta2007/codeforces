namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (x : Qubit[], y : Qubit) : Unit {
        body (...) {
            let N = Length(x);
            for (i in 0..N-1) {
                X(x[i]);
            }
            Controlled X (x, y);
            for (i in 0..N-1) {
                X(x[i]);
            }
            for (i in 0..N-1) {
                for (j in i+1..N-1) {
                    for (k in j+1..N-1) {
                        Controlled X ([x[i], x[j], x[k]], y);
                    }
                }
            }
            for (i in 0..N-1) {
                for (j in i+1..N-1) {
                    for (k in j+1..N-1) {
                        for (l in k+1..N-1) {
                            for (m in l+1..N-1) {
                                for (n in m+1..N-1) {
                                    Controlled X ([x[i], x[j], x[k], x[l], x[m], x[n]], y);
                                }
                            }
                        }
                    }
                }
            }
            if (N == 9) {
                Controlled X (x, y);
            }
        }
        adjoint auto;
    }
}