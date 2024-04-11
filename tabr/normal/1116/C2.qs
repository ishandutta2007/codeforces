namespace Solution
{
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Arrays;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Diagnostics;
    open Microsoft.Quantum.Convert;

    // operation Solve (qs : Qubit[]) : Unit {
    //     let n = Length(qs);
    //     H(qs[0]);
    //     Controlled H([qs[2]],qs[1]);
    // }

    operation Solve (x : Qubit[], y : Qubit) : Unit {
        body (...) {
            let n=Length(x); 
            let max=1<<<n;
            for(j in 0..max-1){
                let bin=IntAsBoolArray(j,n);
                if(Eval(bin,n)){
                    for(k in 0 .. n - 1){
                        if(bin[k]==false){
                            X(x[k]);
                        }
                    }
                    Controlled X(x,y);
                    for(k in 0..n-1){
                        if(bin[k]==false){
                            X(x[k]);
                        }
                    }
                }
            }
        }
        adjoint auto;
    }

    function Eval(j:Bool[],n:Int) : Bool{
        for(i in 1..n-1){
            mutable b=true;
            for(k in 0..n-1-i){
                if(j[k]!=j[k+i]){
                    set b = false;
                }
            }
            if(b){
                return true;
            }
        }
        return false;
    }

    operation DumpUnitaryToFiles (N : Int, unitary : (Qubit[] => Unit)) : Unit {
        let size = 1 <<< N;
        using (qs = Qubit[N]) {
            for (k in 0 .. size - 1) {                
                let binary = IntAsBoolArray(k, N);
                ApplyPauliFromBitString(PauliX, true, binary, qs);
                unitary(qs);
                DumpMachine($"DU_{N}_{k}.txt");
                ResetAll(qs);
            }
        }
    }

    operation CallDumpUnitary (N : Int) : Unit {
        let unitary = ApplyToEach(I, _);
        // let unitary = Solve;
        DumpUnitaryToFiles(N, unitary);
    }
}

// ApplyToEach(X, qs);
// Controlled X(qs, q);  ==  (ControlledOnInt(1, X))(qs, q); 
// ApplyToEach(Controlled X([q], _), qs);