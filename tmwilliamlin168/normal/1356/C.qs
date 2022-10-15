namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Measurement;
    open Microsoft.Quantum.Math;
    open Microsoft.Quantum.Convert;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Arithmetic;
	
	operation Solve (qs : Qubit[]) : Unit {
        using(q=Qubit()) {
			repeat {
				ResetAll(qs);
				ApplyToEach(H, qs);
				(ControlledOnInt(0, X))(qs, q);
			} until(MResetZ(q)==Zero);
		}
    }
}