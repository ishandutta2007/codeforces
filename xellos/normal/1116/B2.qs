namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Extensions.Math;

    operation Solve (q : Qubit) : Int
    {
        mutable res = -1;
        using (h = Qubit()) {
            // [q, h]
            // |A> == |00> + |10>
            // |B> == |00> + om |10>
            // |C> == |00> + om* |10>
            H(h);
            // |A> == |00> + |10> + |01> + |11>
            // |B> == |00> + om |10> + |01> + om |11>
            // |C> == |00> + om* |10> + |01> + om* |11>
            (Controlled H)([h], q);
            // |A> == |00> + |10> + sqrt2 |01>
            // |B> == |00> + om |10> - om*/sqrt2 |01> + (1-om)/sqrt2 |11>
            // |C> == |00> + om* |10> - om/sqrt2 |01> + (1-om*)/sqrt2 |11>
            X(q);
            let alpha = -2. * ArcTan(Sqrt(2.));
            (Controlled Ry)([q], (alpha, h));
            X(q);
            // |A> == sqrt3 |00> +     |10>
            // |B> == (1-om*)/sqrt3 |00> - (1-om)/sqrt6  |01> + om  |10> + (1-om)/sqrt2  |11>
            //     == -om i |00> + om  |10> - i om*/sqrt2 |01> + (1-om)/sqrt2  |11>
            // |C> == (1-om)/sqrt3  |00> - (1-om*)/sqrt6 |01> + om* |10> + (1-om*)/sqrt2 |11>
            //     == om* i |00> + om* |10> + i om/sqrt2  |01> + (1-om*)/sqrt2 |11>
            X(q);
            R1(PI() * 3. / 2., q);
            X(q);
            // |A> == i sqrt3 |00> +     |10>
            // |B> == -om     |00> + om  |10> - om*/sqrt2 |01> + (1-om)/sqrt2  |11>
            // |C> == om*     |00> + om* |10> + om/sqrt2  |01> + (1-om*)/sqrt2 |11>
            let valh = M(h);
            if (valh == One) {
                set res = 0;
                X(h);
            }
            else {
                // |A> == i sqrt3 |0> + |1>
                // |B> == -om |0> + om |1>
                // |C> == om* |0> + om* |1>
                H(q);
                // |B> == -om |1>
                // |C> == om* |0>
                let valq = M(q);
                if (valq == One) {
                	set res = 2;
                }
                else {
                	set res = 1;
                }
            }
        }
        return res;
    }
}