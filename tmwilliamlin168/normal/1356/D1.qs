namespace Solution {
    open Microsoft.Quantum.MachineLearning;
    
    function ClassifierStructure() : ControlledRotation[] {
		return [ControlledRotation((0, new Int[0]), PauliY, 0)];
	}

    operation Solve () : (ControlledRotation[], (Double[], Double)) {
        return (ClassifierStructure(), ([3.1307232387918753], -0.0013000000000000234));
    }
}