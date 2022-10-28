#include<bits/stdc++.h>
using namespace std;

const int MX = 11;
const int MXQ = 50;
const int M = 1e6 + 3;

int add(int a, int b) {
	return a + b < M ? a + b : a + b - M;
}
int sub(int a, int b) {
	return a - b < 0 ? a - b + M : a - b;
}

int vals[M][MX + 1];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	for (int i = 0; i < MXQ; ++i) {
		cout << "? " << i << endl;
		cin >> vals[i][0];
	}
	for (int i = 1; i <= MX; ++i) {
		for (int j = 0; j < MXQ - i; ++j) {
			vals[j][i] = sub(vals[j + 1][i - 1], vals[j][i - 1]);
		}
	}
	assert(!vals[0][MX]);
	
	for (int i = 1; i < M; ++i) {
		for (int j = MX - 1; j >= 0; --j) {
			vals[i][j] = add(vals[i - 1][j], vals[i - 1][j + 1]);
		}
	}

	for (int i = 0; i < M; ++i) {
		if (!vals[i][0]) {
			cout << "! " << i << endl;
			return 0;
		}
	}
	cout << "! " << -1 << endl;
}