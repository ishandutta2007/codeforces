        
namespace Solution {
    open Microsoft.Quantum.Intrinsic;

    operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        using(q=Qubit()){
            unitary(q);
            let i=M(q);
            Reset(q);
            if (i==Zero) {
                return 0;
            } else {
                return 1;
            }
        }
    }
}