namespace Solution {
	open Microsoft.Quantum.Math;
	open Microsoft.Quantum.Canon;
	open Microsoft.Quantum.Intrinsic;
	open Microsoft.Quantum.Diagnostics;
	open Microsoft.Quantum.Convert;
	
	operation Inc (a : Qubit[]) : Unit is Adj + Ctl {
		let n = Length(a);
		if (n > 1) {
			(Controlled Inc)([a[0]], a[1..n-1]);
		}
		X(a[0]);
	}

	operation Solve (a : Qubit[], w : Qubit) : Unit is Adj + Ctl {
		let n = Length(a);
		using (q = Qubit[n]) {
			for (i in 1..(n/2)) { Inc(q); }
			for (i in 0..n-1) { (Controlled Adjoint Inc)([a[i]], q); }
			for (i in 0..n-1) { X(q[i]); }
			(Controlled X)(q, w);
			for (i in 0..n-1) { X(q[i]); }
			for (i in 0..n-1) { (Controlled Inc)([a[i]], q); }
			for (i in 1..(n/2)) { (Adjoint Inc)(q); }
		}
	}
}