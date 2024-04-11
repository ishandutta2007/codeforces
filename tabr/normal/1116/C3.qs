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
            using (a=Qubit[2]){
                f(x,a);
                (ControlledOnInt(0,X))(a,y);
                Adjoint f(x,a);
            }
        }
        adjoint auto;
    }

    operation f(x:Qubit[],a:Qubit[]) : Unit
    is Adj + Ctl {
        let n=Length(x);
        for(i in 0..n-1){
            Controlled add(x[i..i],a);
        }
    }

    operation add(a:Qubit[]) : Unit
    is Adj + Ctl {
        CNOT(a[0],a[1]);
        X(a[0]);
        using (q=Qubit[1]){
            Controlled X(a,q[0]);
            CNOT(q[0],a[0]);
            CNOT(q[0],a[1]);
            (ControlledOnInt(0,X))(a,q[0]);
        }
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