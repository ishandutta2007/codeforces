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
        using(sum=Qubit[4]){
            for(i in 0..Length(inputs)-1){
                Controlled Increment([inputs[i]], LittleEndian(sum));
            }
            (ControlledOnInt(Length(inputs)/2, X))(sum, output);
            for(i in 0..Length(inputs)-1){
                Adjoint Controlled Increment([inputs[i]], LittleEndian(sum));
            }
        }
    }
}