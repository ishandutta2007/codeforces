namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation ekzhangaf(x : Qubit[], z : Int[], gamegame : Qubit[]) : Unit {
        body (...) {
            for(i in 0..Length(gamegame)-1) {
                let a=Length(x)-z[i];
                for(j in 0..a-1) {
                    CNOT(x[Length(x)-a+j], x[j]);
                    X(x[j]);
                }
                Controlled X(x[0..a-1], gamegame[i]);
                for(j in 0..a-1) {
                    CNOT(x[Length(x)-a+j], x[j]);
                    X(x[j]);
                }
                X(gamegame[i]);
            }
        }
        adjoint auto;
    }

    operation benqisop (x : Qubit[], y : Qubit, z : Int[]) : Unit {
        body (...) {
            using (gamegame = Qubit[Length(z)]) {
                WithA(ekzhangaf(x, z, _), Controlled X(_, y), gamegame);
                X(y);
            }
        }
        adjoint auto;
    }

    operation Solve (x : Qubit[], y : Qubit) : Unit {
        body (...) {
            let n=Length(x);
            if(n==2) {
                benqisop(x, y, [1]);
            } elif (n==3) {
                benqisop(x, y, [2]);
            } elif (n==4) {
                benqisop(x, y, [2, 3]);
            } elif (n==5) {
                benqisop(x, y, [3, 4]);
            } elif (n==6) {
                benqisop(x, y, [3, 4, 5]);
            } else {
                benqisop(x, y, [4, 5, 6]);
            }
        }
        adjoint auto;
    }
}