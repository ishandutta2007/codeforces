namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : Int
    {
        body
        {
            mutable cnt = 0;
            for(i in 0..Length(qs)-1) {
                let ret = M(qs[i]);
                if(ret == One) {
                    set cnt = cnt+1;
                }
            }
            if(cnt == 1) {
                return 1;
            }
            return 0;
        }
    }
}