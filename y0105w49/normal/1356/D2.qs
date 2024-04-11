namespace Solution {
    open Microsoft.Quantum.Convert;
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Arrays;
    open Microsoft.Quantum.MachineLearning;
    open Microsoft.Quantum.Math;


    function badClassifierStructure() : ControlledRotation[] {
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

    // The definition of classifier structure for the case when the data is linearly separable and fits into 1 qubit
    function ClassifierStructure() : ControlledRotation[] {
        return [
            ControlledRotation((0, new Int[0]), PauliX, 0),
            ControlledRotation((0, new Int[0]), PauliY, 1),
            ControlledRotation((0, new Int[0]), PauliZ, 2),
            ControlledRotation((0, new Int[0]), PauliX, 3),
        ];
    }


    operation Solve () : (ControlledRotation[], (Double[], Double)) {
        body(...) {
            let parameters = [1.8346911937981, 4.60743032369173, 3.77632003995283, 2.38103913799723, 1.0375024683771, 1.2284197835480999, 4.101039669018601, 5.2370914344804];
            let bias = 0.20079999999999998;
            return (ClassifierStructure(), (parameters, bias));
        }
    }
}