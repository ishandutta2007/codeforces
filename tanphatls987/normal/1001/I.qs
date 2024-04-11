namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Extensions.Testing; //for debug purpose

    //Measure a qubit then set it to the desire value.
    operation Set (q1: Qubit, desired : Result) : Unit {
        let current = M(q1); 
        if (current != desired) {
            X(q1);
        }
    }
    //Build suitable state for Deutsch-Jorsa algorithm.
    operation Preset(supplyInput : Qubit[], supplyOutput : Qubit) : Unit {
        let N = Length(supplyInput);
        for (i in 0..N - 1) {
            Set(supplyInput[i], Zero);
            H(supplyInput[i]);
        }
        Set(supplyOutput, One);
        H(supplyOutput);
    }
    
    //Check final state is (0 ** n) or not.
    operation getResult(A : Qubit[]) : Bool {
        let N = Length(A);
        for (i in 0..N - 1) {
            H(A[i]);
        }
        for (i in 0..N - 1) {
            if (M(A[i]) == One) {
                return false;
            }
        }
        return true;
    }

    operation Solve (N : Int, Uf : ((Qubit[], Qubit) => Unit)) : Bool
    {
        body
        {
            mutable result = true;
            using (answerUf = Qubit()) {
                using (A = Qubit[N]) {
                    Preset(A, answerUf);
                    Uf(A, answerUf);
                    set result = getResult(A);
                    ResetAll(A); ///homekeeping tasks
                    Reset(answerUf);
                }
            }
            return result;
        }
    }
}