namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Math;
    open Microsoft.Quantum.Arrays;
    open Microsoft.Quantum.Canon;

    operation go (inputs : Qubit[], output : Qubit, cnt1: Int, cur: Int, N: Int) : Unit is Adj+Ctl {
        if (N == cur) {
            Controlled X(inputs, output);
        } else {
            if (cnt1 * 2 < N) {
                X(inputs[cur]);
                go(inputs, output, cnt1 + 1, cur + 1, N);
                X(inputs[cur]);
            }
            if ((cnt1 + N - cur) * 2 > N) {
                go(inputs, output, cnt1, cur + 1, N);
            }
        }
    }

    operation Solve (inputs : Qubit[], output : Qubit) : Unit is Adj+Ctl {
        let n = Length(inputs);
        go(inputs, output, 0, 0, n);
    }
}