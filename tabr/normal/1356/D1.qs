namespace Solution {
    open Microsoft.Quantum.MachineLearning;

    function ClassifierStructure() : ControlledRotation[] {
        return [
            ControlledRotation((0, new Int[0]), PauliY, 0)
        ];
    }
    
    operation Solve(): (ControlledRotation[], (Double[], Double)) {
        let a = ClassifierStructure();
        let b = [-3.1411247628010535,3.0046189860522,2.0304238543083004,0.6351429523527,1.0169578650428999,1.3043836295919,4.101039669018601,5.4508284586404];
        let c = 0.00640294168550078;
        return (a, (b, c));
    }
}