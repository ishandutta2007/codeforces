namespace Solution {
	open Microsoft.Quantum.Primitive;
	open Microsoft.Quantum.Canon;

	operation Solve (x : Qubit[], y : Qubit) : Unit
	{
		body (...) {
			let N = Length(x);
			CNOT(x[N-1], x[0]);
			X(x[0]);
			CNOT(x[0], y);
			X(x[0]);
			// assuming x[0] == 1 (first and last bit different originally)
			if (N >= 4) {
				CNOT(x[N-1], x[1]);
				X(x[1]);
				CNOT(x[N-1], x[N-2]);

				(Controlled X)([x[0], x[1], x[N-2]], y);

				if (N >= 6) {
					CNOT(x[N-1], x[N-3]);
					CNOT(x[N-1], x[2]);
					X(x[2]);

					X(x[N-2]);
					(Controlled X)([x[0], x[1], x[2], x[N-3], x[N-2]], y);
					X(x[N-2]);

					X(x[1]);
					(Controlled X)([x[0], x[1], x[2], x[N-3], x[N-2]], y);
					X(x[1]);

					X(x[2]);
					CNOT(x[N-1], x[2]);
					CNOT(x[N-1], x[N-3]);
				}

				CNOT(x[N-1], x[N-2]);
				X(x[1]);
				CNOT(x[N-1], x[1]);
			}
			CNOT(x[N-1], x[0]);
		}
		adjoint auto;
	}
}