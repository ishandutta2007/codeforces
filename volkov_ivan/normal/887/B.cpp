#include <iostream>

using namespace std;

int num(int a, int b, int c) {
	return a * 100 + b * 10 + c;
}

int main() {
	bool poss[1001];
	for (int i = 0; i <= 1000; i++) {
		poss[i] = 0;
	}
	int n, now;
	cin >> n;
	int a[n][6];
	for (int i = 0; i < n; i++) {
		cin >> a[i][0] >> a[i][1] >> a[i][2] >> a[i][3] >> a[i][4] >> a[i][5];
	}
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			for (int k = 0; k < 6; k++) {
				poss[a[0][i]] = 1;
				if (n > 1) {
					poss[a[1][j]] = 1;
					poss[a[0][i] * 10 + a[1][j]] = poss[a[1][j] * 10 + a[0][i]] = 1;
				}
				if (n > 2) {
					poss[a[2][k]] = 1;
					poss[a[0][i] * 10 + a[2][k]] = poss[a[2][k] * 10 + a[0][i]] = 1;
					poss[a[1][j] * 10 + a[2][k]] = poss[a[2][k] * 10 + a[1][j]] = 1;
					poss[num(a[0][i], a[1][j], a[2][k])] = poss[num(a[0][i], a[2][k], a[1][j])] = 1;
					poss[num(a[1][j], a[0][i], a[2][k])] = poss[num(a[1][j], a[2][k], a[0][i])] = 1;
					poss[num(a[2][k], a[0][i], a[1][j])] = poss[num(a[2][k], a[1][j], a[0][i])] = 1;
				}
			}
		}
	}
	for (int i = 1; i <= 1000; i++) {
		if (!poss[i]) {
			cout << i - 1 << endl;
			return 0;
		}
	}
}