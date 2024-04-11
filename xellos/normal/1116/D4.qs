namespace Solution {
	open Microsoft.Quantum.Primitive;
	open Microsoft.Quantum.Canon;

	operation IncrementBinaryRepresentation (qs : Qubit[]) : Unit {
	/// Let the state of qs represent an integer x in little endian format.
	/// Transforms state |x> into |(x+1) % 2^Length(qs)>.
		body (...) {
			for (i in Length(qs)-1..-1..0) {
				(Controlled X)(qs[0..i-1], qs[i]);
			}
		}

		controlled (c, ...) {
			for (i in Length(qs)-1..-1..0) {
				(Controlled X)(c + qs[0..i-1], qs[i]);
			}
		}
	}

	operation Solve (qs : Qubit[]) : Unit
	{
		X(qs[Length(qs)-1]);
		(Controlled IncrementBinaryRepresentation)([qs[Length(qs)-1]], qs[0..Length(qs)-2]);
		for (i in 0..Length(qs)-2) {
			CNOT(qs[Length(qs)-1], qs[i]);
		}
		X(qs[Length(qs)-1]);
		for (i in 0..Length(qs)-2) {
			CNOT(qs[Length(qs)-1], qs[i]);
		}
		(Controlled IncrementBinaryRepresentation)([qs[Length(qs)-1]], qs[0..Length(qs)-2]);
		for (i in Length(qs)-1..-1..1) {
			CNOT(qs[i-1], qs[i]);
		}
		H(qs[0]);
		for (i in 0..Length(qs)-2) {
			CNOT(qs[i], qs[i+1]);
		}
	}
}