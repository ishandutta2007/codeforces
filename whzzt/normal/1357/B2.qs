namespace Solution {
	open Microsoft.Quantum.Math;
	open Microsoft.Quantum.Canon;
	open Microsoft.Quantum.Intrinsic;
	open Microsoft.Quantum.Diagnostics;
	open Microsoft.Quantum.Convert;
	
	operation Inc (a : Qubit[]) : Unit is Adj + Ctl {
		using (q = Qubit[1]) {
			CNOT(a[1], q[0]); CNOT(a[0], a[1]); X(a[0]);
			CNOT(q[0], a[1]); CNOT(q[0], a[0]);
			X(a[0]); X(a[1]);
			CCNOT(a[0], a[1], q[0]);
			X(a[0]); X(a[1]);
		}
	}
	operation Count (a : Qubit[], q : Qubit[]) : Unit is Adj + Ctl {
		SWAP(q[0], q[1]);
		let n = Length(a);
		(Controlled Inc)([a[n-1]], q);
		if (n > 1) { Count(a[0..n-2], q); }
	}
	operation Solve (a : Qubit[], w : Qubit) : Unit is Adj + Ctl {
		let n = Length(a);
		using (q = Qubit[2]) {
			Count(a, q);
			X(q[0]); X(q[1]);
			(Controlled X)(q, w);
			X(q[0]); X(q[1]);
			Adjoint Count(a, q);
		}
	}
}