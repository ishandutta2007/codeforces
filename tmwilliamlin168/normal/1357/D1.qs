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
		return ((1, [1.4]), ClassifierStructure(), ([4.382248057252344,2.24241876106209,0.35987716444887385,3.0658942421931394,1.8704119052447348,0.8825051777481098,4.857102706738436,3.726433260408799], -0.03528784938225171));
	}
}