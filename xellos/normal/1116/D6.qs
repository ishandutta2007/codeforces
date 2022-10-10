namespace Solution {
	open Microsoft.Quantum.Primitive;
	open Microsoft.Quantum.Canon;
	open Microsoft.Quantum.Extensions.Math;

	operation MixAdjacentStates (qs : Qubit[], bits : Bool[], d : Double) : Unit {
	/// Expects d in [0, 1]; d != 1/2.
	/// Bits are in little endian format.
	/// If bits == [true, ..., true], acts as the identity transformation. Otherwise transforms states:
	///   - |bits>   to sqrt(d) |bits>   - sqrt(1-d) |bits+1> 
	///   - |bits+1> to sqrt(d) |bits+1> + sqrt(1-d) |bits>
	/// and acts as the identity transformation on all other states.
		mutable firstZero = -1;
		for (i in 0..Length(qs)-1) {
			if (firstZero == -1 && not bits[i]) {
				set firstZero = i;
			}
		}
		for (i in firstZero+1..Length(qs)-1) {
			if (not bits[i]) {
				X(qs[i]);
			}
		}
		if (firstZero != -1) {
			for (i in 0..firstZero-1) {
				CNOT(qs[firstZero], qs[i]);
			}
			let theta = -2.0 * ArcSin(Sqrt(1.0-d));
			let control = qs[0..firstZero-1] + qs[firstZero+1..Length(qs)-1];
			(Controlled Ry)(control, (theta, qs[firstZero]));
			for (i in 0..firstZero-1) {
				CNOT(qs[firstZero], qs[i]);
			}
		}
		for (i in firstZero+1..Length(qs)-1) {
			if (not bits[i]) {
				X(qs[i]);
			}
		}
	}

	operation Solve (qs : Qubit[]) : Unit
	{
		let L = 1 <<< Length(qs);
		for (i in L-2..-1..0) {
			MixAdjacentStates(qs, BoolArrFromPositiveInt(i, Length(qs)), 0.1);
		}
	}
}