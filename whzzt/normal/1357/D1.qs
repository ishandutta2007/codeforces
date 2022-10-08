namespace Solution {
	open Microsoft.Quantum.Intrinsic;
	open Microsoft.Quantum.MachineLearning;
	open Microsoft.Quantum.Math;

	function Preprocessing() : (Int, Double[]) {
		return (1, [2.5, 0.0]);
	}

	function Classifier() : ControlledRotation[] {
		return [
			ControlledRotation((1, [0]), PauliY, 0)
			];
	}

	operation Solve () : ((Int, Double[]), ControlledRotation[], (Double[], Double)) {
		return (Preprocessing(), Classifier(), ([PI()], 0.46));
	}

}