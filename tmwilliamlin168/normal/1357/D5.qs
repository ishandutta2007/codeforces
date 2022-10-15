namespace Solution {
	open Microsoft.Quantum.MachineLearning;
	
	function ClassifierStructure() : ControlledRotation[] {
		return [
			ControlledRotation((0, new Int[0]), PauliX, 4),
			ControlledRotation((0, new Int[0]), PauliZ, 5),
			ControlledRotation((1, new Int[0]), PauliX, 6),
			ControlledRotation((1, new Int[0]), PauliZ, 7),
			ControlledRotation((0, [1]), PauliX, 0),
			ControlledRotation((1, [0]), PauliX, 1),
			ControlledRotation((1, new Int[0]), PauliZ, 2),
			ControlledRotation((1, new Int[0]), PauliX, 3)
		];
	}
 
    operation Solve () : ((Int, Double[]), ControlledRotation[], (Double[], Double)) {
		return ((1, [1.0, 1.0]), ClassifierStructure(), ([0.06563092804415736,3.487222989356824,1.7041100761811703,0.2884353183986662,0.8808614421739731,0.9654251272940798,4.1903716002012406,5.618949003123218], 0.2276193355488204));
	}
}