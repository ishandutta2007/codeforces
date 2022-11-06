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
		for (i in 1..((1 <<< N) - 1)) {
			let i2 = (i &&& 0x555) + ((i >>> 1) &&& 0x555);
			let i3 = (i2 &&& 0x333) + ((i2 >>> 2) &&& 0x333);
			let i4 = (i3 &&& 0xF0F) + ((i3 >>> 4) &&& 0xF0F);
			let i5 = (i4 &&& 0x0FF) + ((i4 >>> 8) &&& 0x0FF);
			if (i5 * 2 == N) {
				for (j in 0..(N - 1)) {
					if ((i &&& (1 <<< j)) != 0) {
						X(inputs[j]);
					}
				}
				Controlled X(inputs, output);
				for (j in 0..(N - 1)) {
					if ((i &&& (1 <<< j)) != 0) {
						X(inputs[j]);
					}
				}
			}
		}
	}
}