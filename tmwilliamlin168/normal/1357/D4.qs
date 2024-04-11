namespace Solution {
	open Microsoft.Quantum.MachineLearning;
	
	function ClassifierStructure() : ControlledRotation[] {
		return [
			ControlledRotation((0, [1]), PauliY, 0),
			ControlledRotation((1, [0]), PauliY, 0),
			ControlledRotation((0, [1]), PauliY, 1),
		];
	}
 
    operation Solve () : ((Int, Double[]), ControlledRotation[], (Double[], Double)) {
		return ((1, [1.0, 1.0]), ClassifierStructure(), ([3.14, 3.14], -0.016199999999999992));
	}
}