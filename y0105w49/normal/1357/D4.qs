namespace Solution {
    open Microsoft.Quantum.Convert;
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Arrays;
    open Microsoft.Quantum.MachineLearning;
    open Microsoft.Quantum.Math;


    function rClassifierStructure() : ControlledRotation[] {
        return [
            ControlledRotation((0, new Int[0]), PauliX, 0),
            ControlledRotation((0, new Int[0]), PauliZ, 1),
            ControlledRotation((1, new Int[0]), PauliX, 2),
            ControlledRotation((1, new Int[0]), PauliZ, 3),
            ControlledRotation((2, new Int[0]), PauliX, 4),
            ControlledRotation((2, new Int[0]), PauliZ, 5),
            ControlledRotation((0, [2]), PauliX, 6),
            ControlledRotation((1, [0]), PauliX, 7),
            ControlledRotation((2, [1]), PauliX, 8),
            ControlledRotation((1, [2]), PauliX, 9),
            ControlledRotation((0, [1]), PauliX, 10),
            ControlledRotation((2, [0]), PauliX, 11),
            ControlledRotation((2, new Int[0]), PauliZ, 12),
            ControlledRotation((2, new Int[0]), PauliX, 13),
        ];
    }

    function ClassifierStructure() : ControlledRotation[] {
        return [
            ControlledRotation((0, new Int[0]), PauliX, 3),
            ControlledRotation((0, new Int[0]), PauliZ, 4),
            // ControlledRotation((1, new Int[0]), PauliX, 2),
            // ControlledRotation((1, new Int[0]), PauliZ, 3),
            ControlledRotation((0, [1]), PauliX, 0),
            ControlledRotation((1, [0]), PauliX, 1),
            ControlledRotation((0, [1]), PauliX, 2),
            // ControlledRotation((1, new Int[0]), PauliZ, 7),
            // ControlledRotation((1, new Int[0]), PauliX, 8),
        ];
    }

    // function ClassifierStructure() : ControlledRotation[] {
    //     return new ControlledRotation[0];
    // }

    function zClassifierStructure() : ControlledRotation[] {
        return [
            ControlledRotation((0, [1]), PauliX, 5),
            ControlledRotation((1, [0]), PauliX, 4),
            ControlledRotation((0, [1]), PauliX, 3),
            ControlledRotation((1, new Int[0]), PauliX, 0),
            ControlledRotation((1, new Int[0]), PauliZ, 2),
            ControlledRotation((1, new Int[0]), PauliY, 1),
            // ControlledRotation((1, new Int[0]), PauliX, 0),
            // ControlledRotation((0, new Int[0]), PauliX, 1),
            // ControlledRotation((1, new Int[0]), PauliZ, 2),
            // ControlledRotation((0, new Int[0]), PauliZ, 3),
        ];
    }


    // // The definition of classifier structure for the case when the data is linearly separable and fits into 1 qubit
    // function ClassifierStructure() : ControlledRotation[] {
    //     return [
    //         // ControlledRotation((0, new Int[0]), PauliX, 0),
    //         ControlledRotation((0, new Int[0]), PauliY, 0),
    //         // ControlledRotation((0, new Int[0]), PauliZ, 2),
    //         // ControlledRotation((0, new Int[0]), PauliX, 3),
    //     ];
    // }


    operation Solve () : ((Int, Double[]), ControlledRotation[], (Double[], Double)) {
        body(...) {
            let parameters = [0.0, 0.0, 0.0, 0.0, 0.0];
            let bias = 0.0;
            let mode = 1;
            let auxil = [0.3];
            return ((mode, auxil), ClassifierStructure(), (parameters, bias));
        }
    }
}