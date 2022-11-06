namespace Solution {
	open Microsoft.Quantum.Arithmetic;
	open Microsoft.Quantum.Canon;
	open Microsoft.Quantum.Convert;
	open Microsoft.Quantum.Diagnostics;
	open Microsoft.Quantum.Intrinsic;
	open Microsoft.Quantum.MachineLearning;
	open Microsoft.Quantum.Math;
	open Microsoft.Quantum.Measurement;

	operation Solve () : ((Int, Double[]), ControlledRotation[], (Double[], Double)) {
		let parameters = [3.1212094973126265, 0.6488034903276707, 1.2622588508445296, 3.547203550987554, 3.409812233043679, 4.358879606729504, 2.642437058957734, 2.536337772832807];
		let bias = 0.2031;
		return ((4, [1.0, 1.0]), Structure(), (parameters, bias));
	}

	function Structure() : ControlledRotation[] {
		return [
			ControlledRotation((0, new Int[0]), PauliX, 4),
			ControlledRotation((0, new Int[0]), PauliZ, 5),
			ControlledRotation((1, new Int[0]), PauliX, 6),
			ControlledRotation((1, new Int[0]), PauliZ, 7),
			ControlledRotation((0, [1]), PauliX, 0),
			ControlledRotation((1, [0]), PauliX, 1),
			ControlledRotation((1, new Int[0]), PauliZ, 2),
			ControlledRotation((1, new Int[0]), PauliX, 3)
		];
	}
}