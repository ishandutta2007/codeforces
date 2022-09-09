namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : Int
    {
        body
        {
            mutable ans=new Int[1];
            set ans[0]=0;
            CNOT(qs[0],qs[1]);
            H(qs[0]);
            if(M(qs[0])==One)
            {
                set ans[0]=ans[0]+1;
            }
            if(M(qs[1])==One)
            {
                set ans[0]=ans[0]+2;
            }
            return ans[0];
        }
    }
}