namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Math;
    open Microsoft.Quantum.Convert;
    open Microsoft.Quantum.Measurement;
    
    function value(theta: Double): Int{
        mutable result=0;
        while(true){
            let x=RealMod(IntAsDouble(result)*theta, 2.*PI(), 0.);
            if(PI()/3.<=x and x<=PI()*2./3.){ return result; }
            
            set result=result+1;
        }
        return -1;
    }
    
    operation Solve (theta : Double, unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        let n=value(theta);
        using(q=Qubit()){
            for(j in 1..50){
                for(i in 1..value(theta)){
                    unitary(q);
                }
                if(MResetZ(q)==One){
                    return 1;
                }
            }
        }
        return 0;
    }
}