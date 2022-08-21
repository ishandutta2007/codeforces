// This file is submitted by the participant
namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.MachineLearning;

    // The operation that the participant has to implement
    // Has to return three things: 
    //  1) the feature engineering to perform (as an index in the array of feature engineering functions and an array of parameters to be used with it)
    //  2) circuit structure (as an array of ControlledRotation)
    //  3) and training results (circuit parameters + bias)
    //
    // The features engineering is built-in and cannot be tweaked by the participant's solution, only chosen from the list 
    // (see quantum-checker.qs for the list of available feature engineering functions)
    //
    operation Solve () : ((Int, Double[]), ControlledRotation[], (Double[], Double)) {
        return ((1,[1.2]), 
                [
                ControlledRotation((1,[0]),PauliZ,0),
                ControlledRotation((1,[0]),PauliI,3),
                ControlledRotation((1,[0]),PauliY,0),
                
                ControlledRotation((0,[1]),PauliY,1),
                
                ControlledRotation((0,[1]),PauliZ,0),
                ControlledRotation((0,[1]),PauliI,3),
                ControlledRotation((0,[1]),PauliY,0),
                
                ControlledRotation((1,[0]),PauliZ,0),
                ControlledRotation((1,[0]),PauliI,3),
                ControlledRotation((1,[0]),PauliY,0),
                
                ControlledRotation((1,new Int[0]),PauliZ,0),
                ControlledRotation((1,new Int[0]),PauliI,3),
                ControlledRotation((1,new Int[0]),PauliY,0),
                
                ControlledRotation((0,[1]),PauliY,2),
                
                ControlledRotation((1,new Int[0]),PauliZ,0),
                ControlledRotation((1,new Int[0]),PauliI,3),
                ControlledRotation((1,new Int[0]),PauliY,0),
                
                ControlledRotation((1,[0]),PauliZ,0),
                ControlledRotation((1,[0]),PauliI,3),
                ControlledRotation((1,[0]),PauliY,0),
                
                ControlledRotation((0,[1]),PauliZ,0),
                ControlledRotation((0,[1]),PauliI,0),
                ControlledRotation((0,[1]),PauliY,0),
                
                ControlledRotation((1,[0]),PauliZ,0),
                ControlledRotation((1,[0]),PauliI,3),
                ControlledRotation((1,[0]),PauliY,0),
                
                ControlledRotation((1,new Int[0]),PauliY,0)
                ],
                ([3.1415926535,0.55*2.,0.2*2.,-3.1415926535],-0.1775));
    }

//0.55 0.2 1.2 (0.435, 0.5) (0.99, 0.1775)
//swap(01,11)
//rotatey(10,11,0.55)
//  //swap(01,11)swap(01,11)
//swap(10,11)
//swap(01,11)
//x0
//rotatey(10,11,0.2)
//x0
//swap(01,11)
//swap(10,11)
//swap(01,11)
}