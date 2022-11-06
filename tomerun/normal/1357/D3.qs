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
		let parameters = [0.0];
		let bias = 0.132;
		return ((1, [0.75, 0.75]), Structure(), (parameters, bias));
	}

	function Structure() : ControlledRotation[] {
		return [
			ControlledRotation((1, new Int[0]), PauliY, 0),
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