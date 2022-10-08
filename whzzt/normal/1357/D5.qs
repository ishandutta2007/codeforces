namespace Solution {
	open Microsoft.Quantum.Intrinsic;
	open Microsoft.Quantum.MachineLearning;
	open Microsoft.Quantum.Math;

	// after long struggle I discover that grid search >> human intelligence >> machine learning

	function Preprocessing() : (Int, Double[]) {
		return (1, [6.86631]);
	}

	function Classifier() : ControlledRotation[] {
		return [
			ControlledRotation((0, new Int[0]), PauliY, 0),
			ControlledRotation((1, new Int[0]), PauliY, 1),
			ControlledRotation((0, new Int[0]), PauliZ, 2),
			ControlledRotation((1, [0]), PauliX, 3)
			];
	}

	operation Solve () : ((Int, Double[]), ControlledRotation[], (Double[], Double)) {
		return (Preprocessing(), Classifier(), ([6.86631, 11.8589, 7.25833, 4.09266], 0.376799));
	}

}