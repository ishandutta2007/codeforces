namespace Solution {
	open Microsoft.Quantum.MachineLearning;
	
	function ClassifierStructure() : ControlledRotation[] {
		return [ControlledRotation((0, new Int[0]), PauliY, 0)];
	}

	operation Solve () : (ControlledRotation[], (Double[], Double)) {
		return (ClassifierStructure(), ([1.0635235814999962], 0.26044999999999996));
	}
}