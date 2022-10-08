namespace Solution {
	open Microsoft.Quantum.Intrinsic;
	open Microsoft.Quantum.MachineLearning;
	open Microsoft.Quantum.Math;

	// lian ni ma, shou wan niu bi

	function Preprocessing() : (Int, Double[]) {
		return (1, [3.0]);
	}

	function Classifier() : ControlledRotation[] {
		return [
			ControlledRotation((1, new Int[0]), PauliI, 0)
			];
	}

	operation Solve () : ((Int, Double[]), ControlledRotation[], (Double[], Double)) {
		return (Preprocessing(), Classifier(), ([0.0], 0.445));
	}

}