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
		H(qs[0]);
		H(qs[1]);
		using (anc = Qubit()) {
			repeat {
				Controlled X([qs[0], qs[1]], anc);
				let outcome = M(anc);
			}
			until(outcome == Zero)
			fixup {
				X(qs[0]);
				H(qs[0]);
				X(qs[1]);
				H(qs[1]);
				X(anc);
			}
			X(qs[0]);
			X(qs[1]);
		}
	}

	operation SolveTest () : Int {
		using (qubits = Qubit[2]) {
			Solve(qubits);
			DumpMachine("dump.txt");
			ResetAll(qubits);
		}
		return 0;
	}
}