namespace Solution {
	open Microsoft.Quantum.Primitive;
	open Microsoft.Quantum.Canon;

	operation Solve (qs : Qubit[], bits : Bool[][]) : Unit
	{
		let N = Length(qs);
		mutable index = [-1, -1, -1];
		for (i in 0..N-1) {
			let b = PositiveIntFromBoolArr([bits[0][i], bits[1][i], bits[2][i], bits[3][i]]);
			if (index[0] == -1 && b != 0 && b != 15) {
				for (j in i+1..N-1) {
					let c = PositiveIntFromBoolArr([bits[0][j], bits[1][j], bits[2][j], bits[3][j]]);
					if (index[0] == -1 && c != 0 && c != 15 && c != b) {
						mutable desc = new Bool[4];
						set desc[PositiveIntFromBoolArr([bits[0][i], bits[0][j]])] = true;
						set desc[PositiveIntFromBoolArr([bits[1][i], bits[1][j]])] = true;
						set desc[PositiveIntFromBoolArr([bits[2][i], bits[2][j]])] = true;
						set desc[PositiveIntFromBoolArr([bits[3][i], bits[3][j]])] = true;
						if (desc[0] && desc[1] && desc[2] && desc[3]) {
							set index[0] = i;
							set index[1] = j;
							set index[2] = N;
						}
						else {
							for (k in j+1..N-1) {
								mutable desc3 = new Bool[8];
								set desc3[PositiveIntFromBoolArr([bits[0][i], bits[0][j], bits[0][k]])] = true;
								set desc3[PositiveIntFromBoolArr([bits[1][i], bits[1][j], bits[1][k]])] = true;
								set desc3[PositiveIntFromBoolArr([bits[2][i], bits[2][j], bits[2][k]])] = true;
								set desc3[PositiveIntFromBoolArr([bits[3][i], bits[3][j], bits[3][k]])] = true;
								mutable sum = 0;
								for (l in 0..7) {
									if (desc3[l]) {
										set sum = sum + 1;
									}
								}
								if (index[0] == -1 && sum == 4) {
									set index[0] = i;
									set index[1] = j;
									set index[2] = k;
								}
							}
						}
					}
				}
			}
		}
		if (index[2] == N) {
			mutable coef = new Double[1<<<2];
			for (i in 0..3) {
				let pos = PositiveIntFromBoolArr([bits[i][index[1]], bits[i][index[0]]]);
				set coef[pos] = 1.0;
			}
			let op = StatePreparationPositiveCoefficients(coef);
			let qs_pivot = BigEndian([qs[index[0]], qs[index[1]]]);
			op(qs_pivot);
		}
		else {
			mutable coef = new Double[1<<<3];
			for (i in 0..3) {
				let pos = PositiveIntFromBoolArr([bits[i][index[2]], bits[i][index[1]], bits[i][index[0]]]);
				set coef[pos] = 1.0;
			}
			let op = StatePreparationPositiveCoefficients(coef);
			let qs_pivot = BigEndian([qs[index[0]], qs[index[1]], qs[index[2]]]);
			op(qs_pivot);
		}
		for (i in 0..N-1) {
			for (j in 0..3) {
				if (i != index[0] && i != index[1] && i != index[2] && bits[j][i]) {
					if (not bits[j][index[0]]) {
						X(qs[index[0]]);
					}
					if (not bits[j][index[1]]) {
						X(qs[index[1]]);
					}
					if (index[2] != N) {
						if (not bits[j][index[2]]) {
							X(qs[index[2]]);
						}
						(Controlled X)([qs[index[0]], qs[index[1]], qs[index[2]]], qs[i]);
						if (not bits[j][index[2]]) {
							X(qs[index[2]]);
						}
					}
					else {
						(Controlled X)([qs[index[0]], qs[index[1]]], qs[i]);
					}
					if (not bits[j][index[0]]) {
						X(qs[index[0]]);
					}
					if (not bits[j][index[1]]) {
						X(qs[index[1]]);
					}
				}
			}
		}
	}
}