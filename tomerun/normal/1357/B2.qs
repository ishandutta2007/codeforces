namespace Solution {
	open Microsoft.Quantum.Arithmetic;
	open Microsoft.Quantum.Convert;
	open Microsoft.Quantum.Diagnostics;
	open Microsoft.Quantum.Extensions.Convert;
	open Microsoft.Quantum.Math;
	open Microsoft.Quantum.Measurement;
	open Microsoft.Quantum.Canon;
	open Microsoft.Quantum.Intrinsic;

	operation Solve (inputs : Qubit[], output : Qubit) : Unit is Adj + Ctl {
		let N = Length(inputs);
		for (i in 0..((1 <<< N) - 1)) {
			if (i % 3 == 0) {
				for (j in 0..(N - 1)) {
					if ((i &&& (1 <<< j)) == 0) {
						X(inputs[j]);
					}
				}
				Controlled X(inputs, output);
				for (j in 0..(N - 1)) {
					if ((i &&& (1 <<< j)) == 0) {
						X(inputs[j]);
					}
				}
			}
		}
	}
 }