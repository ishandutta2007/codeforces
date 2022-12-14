namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Arithmetic;
    open Microsoft.Quantum.Canon;

    operation Increment(register : LittleEndian) : Unit is Adj+Ctl {
        for(i in Length(register!)-1..-1..0){
            Controlled X(register![0..1..(i-1)], register![i]);
        }
    }
    operation Solve (inputs : Qubit[], output : Qubit) : Unit is Adj+Ctl {
        using(sum=Qubit[3]){
            for(i in 0..Length(inputs)-1){
                if(i%2==0){
                    Controlled Increment([inputs[i]], LittleEndian(sum));
                }else{
                    Adjoint Controlled Increment([inputs[i]], LittleEndian(sum));
                }
            }
            (ControlledOnInt(0, X))(sum, output);
            (ControlledOnInt(3, X))(sum, output);
            (ControlledOnInt(5, X))(sum, output);
            for(i in 0..Length(inputs)-1){
                if(i%2==0){
                    Adjoint Controlled Increment([inputs[i]], LittleEndian(sum));
                }else{
                    Controlled Increment([inputs[i]], LittleEndian(sum));
                }
            }
        }
    }
}