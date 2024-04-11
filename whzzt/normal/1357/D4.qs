namespace Solution {
	open Microsoft.Quantum.Intrinsic;
	open Microsoft.Quantum.MachineLearning;
	open Microsoft.Quantum.Math;

	// after long struggle I discover that human intelligence > machine learning

	function Preprocessing() : (Int, Double[]) {
		return (1, [0.3]);
	}

	function Classifier() : ControlledRotation[] {
		return [
			ControlledRotation((0, new Int[0]), PauliI, 0)
			];
	}

	operation Solve () : ((Int, Double[]), ControlledRotation[], (Double[], Double)) {
		return (Preprocessing(), Classifier(), ([0.0], 0.0));
	}

}