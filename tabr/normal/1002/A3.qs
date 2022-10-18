namespace Solution
{
    open Microsoft.Quantum.Arithmetic;
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Arrays;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Diagnostics;
    open Microsoft.Quantum.Convert;
    open Microsoft.Quantum.Math;

    operation Solve (qs : Qubit[], bits0 : Bool[], bits1 : Bool[]) : Unit {
        let n = Length(qs);
        mutable j=-1;
        mutable t=0;
        for(i in 0..n-1){
            if(j!=-1){
                if(bits0[i]){
                    (ControlledOnInt(t,X))(qs[j..j],qs[i]);
                }
                if(bits1[i]){
                    (ControlledOnInt(1-t,X))(qs[j..j],qs[i]);
                }
            }else{
                if(bits0[i]==bits1[i]){
                    if(bits0[i]){
                        X(qs[i]);
                    }
                }else{
                    H(qs[i]);
                    set j=i;
                    if(bits0[i]){
                        set t=1;
                    }
                }
            }
        }
    }

    operation Deutsch_Jozsa (n : Int, u : ((Qubit[], Qubit) => Unit)) : Bool {
        mutable res = true;
        using ((x, y) = (Qubit[n], Qubit())) {
            X(y);
            H(y);
            for (i in 0..n - 1) {
                H(x[i]);
            }
            u(x, y);
            H(y);
            for (i in 0..n - 1) {
                H(x[i]);
                if (M(x[i]) != Zero) {
                    set res = false;
                }
            }
            ResetAll(x);
            Reset(y);
        }
        return res;
    }

    operation Set (desired: Result, q1: Qubit) : Unit {
        let current = M(q1);
        if (desired != current) { X(q1); }
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
        // let unitary = ApplyToEach(I, _);
        let unitary = Solve;
        // DumpUnitaryToFiles(N, unitary);
    }
}

// ApplyToEach(X, qs);
// Controlled X(qs, q);  ==  (ControlledOnInt(1, X))(qs, q); 
// ApplyToEach(Controlled X([q], _), qs);