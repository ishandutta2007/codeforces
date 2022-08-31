namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Convert;
    
    operation Solve (qs : Qubit[], bits0 : Bool[], bits1 : Bool[]) : Int
    {
        let N = Length(qs);
        for (i in 0 .. N - 1) {
            if(bits0[i] != bits1[i]) {
                if(ResultAsBool(M(qs[i])) == bits0[i]) {
                    return 0;
                }
                else {
                    return 1;
                }
            }
        }
        return -1;
    }
}