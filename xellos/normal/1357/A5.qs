namespace Solution {
	open Microsoft.Quantum.Intrinsic;
	open Microsoft.Quantum.Measurement;
	open Microsoft.Quantum.Math;

	operation Solve (theta : Double, unitary : (Qubit => Unit is Adj+Ctl)) : Int {
		mutable ans = 0;
		using (q = Qubit()) {
			mutable p = 1.;
			repeat {
				mutable ang = 0.;
				repeat {
					set ang = ang + theta;
					unitary(q);
				}
				until (AbsD(Sin((ang+theta)/2.)) < AbsD(Sin(ang/2.)))
				fixup {};
				set p = p * Cos(ang/2.) * Cos(ang/2.);
				set ans = (MResetZ(q) == One) ? 1 | ans;
				Reset(q);
			}
			until (p < 1e-10)
			fixup {};
		}
		return ans;
	}
}