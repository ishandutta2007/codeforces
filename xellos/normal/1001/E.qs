namespace Solution {
	open Microsoft.Quantum.Primitive;
	open Microsoft.Quantum.Canon;

	operation Solve (qs : Qubit[]) : Int {
		body {
			(Adjoint CNOT)(qs[0], qs[1]);
			(Adjoint H)(qs[0]);
			mutable InitialStates = new Int[2];
			if(M(qs[0]) == Zero) {
				set InitialStates[0] = 0;
			}
			else {
				set InitialStates[0] = 1;
			}
			if(M(qs[1]) == Zero) {
				set InitialStates[1] = 0;
			}
			else {
				set InitialStates[1] = 1;
			}
			return InitialStates[1]*2+InitialStates[0];
		}
	}
}