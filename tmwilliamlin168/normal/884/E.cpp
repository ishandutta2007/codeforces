#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 16384;

int n, m, K, R;

char S[MAXN];

int A[2][MAXN], B[2][MAXN], FA[MAXN << 1], C[MAXN << 1];

int Find(int x) {
	return FA[x] == x ? x : FA[x] = Find(FA[x]);
}

int main() {
	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		scanf("%s", S);

		int X = i % 2, Y = (i + 1) % 2;

		for (int j = 0; j < m / 4; j++) {
			int x;
			if (S[j] >= '0' && S[j] <= '9')
				x = S[j] - '0';
			else
				x = S[j] - 'A' + 10;

			int y = 4 * j;
			A[X][y + 3] = (x & 1) >> 0;
			A[X][y + 2] = (x & 2) >> 1;
			A[X][y + 1] = (x & 4) >> 2;
			A[X][y + 0] = (x & 8) >> 3;
		}

		for (int j = 0; j < m; j++)
			if (A[X][j] == 1)
				B[X][j] = m + j, R++;

		for (int j = 0; j < 2 * m; j++)
			FA[j] = j, C[j] = -1;

		for (int j = 0; j < m; j++) {
			if (j != 0 && A[X][j] == 1 && A[X][j - 1] == 1) {
				int FU = Find(B[X][j]), FV = Find(B[X][j - 1]);
				if (FU != FV)
					R--, FA[FU] = FV;
			} 
			if (i != 0 && A[X][j] == 1 && A[Y][j - 0] == 1) {
				int FU = Find(B[X][j]), FV = Find(B[Y][j - 0]);
				if (FU != FV)
					R--, FA[FU] = FV;
			}
		}

		for (int j = 0, k = 0; j < m; j++) {
			int FU = Find(B[X][j]);
			if (C[FU] == -1)
				C[FU] = k++;
			B[X][j] = C[FU];
		}
	}
	cout << R << endl;

	return 0;
}