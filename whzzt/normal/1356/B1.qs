namespace Solution {
	open Microsoft.Quantum.Canon;
	open Microsoft.Quantum.Intrinsic;
	open Microsoft.Quantum.Diagnostics;
	open Microsoft.Quantum.Arithmetic;
	
	operation Solve (a : LittleEndian) : Unit is Adj+Ctl {
		let N = Length(a!);
		using (q = Qubit[N+1]) {
			X(q[0]);
			for (i in 0..N-1) {
				CCNOT(q[i], a![i], q[i+1]);
			}
			for (i in N-1..-1..0) {
				CCNOT(q[i], a![i], q[i+1]);
				CNOT(q[i], a![i]);
			}
			X(q[0]);
		}
	}
}