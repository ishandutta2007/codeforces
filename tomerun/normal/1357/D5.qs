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
		let parameters = [5.221116482880964, 1.9581045669301609, 1.368824420367978, 5.540291820972085, 2.1356132822522635, 3.527332928192652, 2.2170804185048154];
		let bias = 0.12753921007018598;
		return ((4, [1.070951180758245, 1.070951180758245]), Structure(), (parameters, bias));
	}

	function Structure() : ControlledRotation[] {
		return [
			ControlledRotation((0, new Int[0]), PauliZ, 0),
			ControlledRotation((1, new Int[0]), PauliZ, 1),
			ControlledRotation((0, new Int[0]), PauliX, 2),
			ControlledRotation((1, new Int[0]), PauliX, 3),
			ControlledRotation((0, [1]), PauliX, 4),
			ControlledRotation((1, [0]), PauliX, 5),
			ControlledRotation((1, new Int[0]), PauliX, 6)
		];
	}
 
	operation SolveTest () : Int {
		let model = Solve();
		// using(qs = Qubit[4]) {
		// 	Solve(10, LittleEndian(qs));
		// 	// DumpMachine("dump.txt");
		// 	Message("10");
		// 	ResetAll(qs);
		// }
		return 0;
	}
}