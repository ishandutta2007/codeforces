namespace Solution
{
	open Microsoft.Quantum.Canon;
	open Microsoft.Quantum.Primitive;
	open Microsoft.Quantum.Extensions.Convert;
	open Microsoft.Quantum.Extensions.Diagnostics;

	operation Solve (qs : Qubit[]) : ()
	{
		body
		{
			ApplyToEach(H, qs);
		}
	}

	operation SolveTest () : (Int)
	{
		body
		{
			for (i in 1..8) {
				using (qubits = Qubit[i]) {
					Solve(qubits);
					DumpMachine(ToStringIFormat(i, "dump-0.\\.txt"));
					ResetAll(qubits);
				}
			}
			return 1;
		}
	}
}