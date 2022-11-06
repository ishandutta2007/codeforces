namespace Solution {
	open Microsoft.Quantum.Arithmetic;
	open Microsoft.Quantum.Convert;
	open Microsoft.Quantum.Diagnostics;
	open Microsoft.Quantum.Extensions.Convert;
	open Microsoft.Quantum.Math;
	open Microsoft.Quantum.Measurement;
	open Microsoft.Quantum.Canon;
	open Microsoft.Quantum.Intrinsic;

	operation Solve (qs : Qubit[]) : Unit {
		let N = Length(qs);
		for (q in qs) {
			H(q);
		}
		using (anc = Qubit()) {
			repeat {
				Controlled X(qs, anc);
				let outcome = M(anc);
			}
			until(outcome == Zero)
			fixup {
				for (q in qs) {
					X(q);
					H(q);
				}
				X(anc);
			}
		}
	}
 
}