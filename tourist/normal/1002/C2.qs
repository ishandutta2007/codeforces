namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (q : Qubit) : Int
    {
        body
        {
            if (RandomInt(2) == 0) {
				if (M(q) == One) {
					return 1;
				} else {
					return -1;
				}
			} else {
				R(PauliY, 1.5707963267948966192313216916398, q);
				if (M(q) == Zero) {
					return 0;
				} else {
					return -1;
				}
			}
        }
    }
}