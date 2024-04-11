namespace Solution {
	open Microsoft.Quantum.MachineLearning;
	
	function ClassifierStructure() : ControlledRotation[] {
		return [
			ControlledRotation((0, [1]), PauliX, 0),
		];
	}
 
	operation Solve () : ((Int, Double[]), ControlledRotation[], (Double[], Double)) {
		return ((1, [2.0]), ClassifierStructure(), ([0.40506267246746697], 0.4003430123549659));
	}
}