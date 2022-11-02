namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Math;
    open Microsoft.Quantum.Arrays;
    open Microsoft.Quantum.Canon;

    operation go (inputs : Qubit[], output : Qubit, cnt1: Int, cur: Int, twoPowerCur: Int, N: Int) : Unit is Adj+Ctl {
        if (N == cur) {
            if ((twoPowerCur - cnt1 - 1) % 3 == 0) {
                Controlled X(inputs, output);
            }
        } else {
            X(inputs[cur]);
            go(inputs, output, cnt1 + twoPowerCur, cur + 1, twoPowerCur * 2, N);
            X(inputs[cur]);
            go(inputs, output, cnt1, cur + 1, twoPowerCur * 2, N);
        }
    }

    operation Solve (inputs : Qubit[], output : Qubit) : Unit is Adj+Ctl {
        let n = Length(inputs);
        go(inputs, output, 0, 0, 1, n);
    }
}