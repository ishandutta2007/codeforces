namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[], bitss : Bool[][]) : Unit {
        let N = Length(qs);
        mutable bits0 = new Bool[N];
        mutable bits1 = new Bool[N];
        mutable bits2 = new Bool[N];
        mutable bits3 = new Bool[N];
        mutable bits = [bits0, bits1, bits2, bits3];
        for (x in 0 .. 3) {
            for (i in 0 .. N - 1) {
                set bits[x][i] = bitss[x][i];
            }
        }
        for (x in 0 .. 3) {
            for (y in x + 1 .. 3) {
                mutable less = 0;
                for (i in N - 1 .. -1 .. 0) {
                    if (bits[x][i] == false && bits[y][i] == true) {
                        set less = 1;
                    }
                    if (bits[x][i] == true && bits[y][i] == false) {
                        set less = -1;
                    }
                }
                if (less == -1) {
                    for (i in 0 .. N - 1) {
                        mutable tmp = bits[x][i];
                        set bits[x][i] = bits[y][i];
                        set bits[y][i] = tmp;
                    }
                }
            }
        }
        mutable have0 = new Bool[N];
        mutable have1 = new Bool[N];
        mutable have2 = new Bool[N];
        mutable have3 = new Bool[N];
        mutable have = [have0, have1, have2, have3];
        H(qs[0]);
        H(qs[1]);
        set have[1][1] = true;
        set have[2][0] = true;
        set have[3][0] = true;
        set have[3][1] = true;
        for (x in 3 .. -1 .. 0) {
            for (i in 2 .. N - 1) {
                if (bits[x][i]) {
                    Controlled X([qs[0], qs[1]], qs[i]);
                    set have[x][i] = true;
                }
            }
            X(qs[1]);
            if (x % 2 == 0) {
                X(qs[0]);
            }
        }
        for (it in 0 .. 10000) {
            let x = RandomInt(4);
            let i = RandomInt(2);
            if (have[x][i] != bits[x][i]) {
                mutable z = -1;
                for (y in 0 .. 3) {
                    mutable match = 1;
                    for (k in 0 .. N - 1) {
                        if (k != i && have[y][k] != have[x][k]) {
                            set match = 0;
                        }
                    }
                    if (match == 1 && x != y) {
                        set z = y;
                    }
                }
                if (z != -1) {
                    for (k in 0 .. N - 1) {
                        mutable tmp = have[x][k];
                        set have[x][k] = have[z][k];
                        set have[z][k] = tmp;
                    }
                } else {
                    for (k in 0 .. N - 1) {
                        if (k != i && not have[x][k]) {
                            X(qs[k]);
                        }
                    }
                    if (i == 0) {
                        Controlled X(qs[1 .. N - 1], qs[0]);
                    } else {
                        Controlled X(qs[0 .. 0] + qs[2 .. N - 1], qs[1]);
                    }
                    set have[x][i] = not have[x][i];
                    for (k in 0 .. N - 1) {
                        if (k != i && not have[x][k]) {
                            X(qs[k]);
                        }
                    }
                }
            }
        }
    }
}