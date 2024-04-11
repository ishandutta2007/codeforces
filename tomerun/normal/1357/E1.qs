namespace Solution {
	open Microsoft.Quantum.Arithmetic;
	open Microsoft.Quantum.Convert;
	open Microsoft.Quantum.Diagnostics;
	open Microsoft.Quantum.Extensions.Convert;
	open Microsoft.Quantum.Math;
	open Microsoft.Quantum.Measurement;
	open Microsoft.Quantum.Canon;
	open Microsoft.Quantum.Intrinsic;

	operation Solve (p : Int, inputRegister : LittleEndian) : Unit is Adj+Ctl {
		let N = Length(inputRegister!);
		let qftp = OperationPowCA(QFTLE, p % 4);
		qftp(inputRegister);
	}
}