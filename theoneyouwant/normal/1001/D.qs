namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (q : Qubit) : Int
    {
        body
        {
            // your code here
            H(q);
            let res = M(q);
            if( res == One){
            return -1;
            }
            else{
            return 1;
            } 
        }
    }
}