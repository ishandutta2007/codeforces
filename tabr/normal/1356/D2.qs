namespace Solution {
    open Microsoft.Quantum.MachineLearning;

    function ClassifierStructure() : ControlledRotation[] {
        return [
            ControlledRotation((0, new Int[0]), PauliY, 0)
        ];
    }
    
    operation Solve(): (ControlledRotation[], (Double[], Double)) {
        let a = ClassifierStructure();
        let b = [1.009039999999996,1.13912,2.3595,4.037552,1.63698,1.27549,0.328671,0.302282];
        let c = 0.2514;
        return (a, (b, c));
    }
}