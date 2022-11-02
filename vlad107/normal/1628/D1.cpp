#include <iostream>
#include <vector>

using namespace std;

const int M = (int)1e9 + 7;

int pw(int x, int y) {
	int res = 1;
	while (y) {
		if (y % 2 == 1) {
			res = (res * 1LL * x) % M;
		}
		x = (x * 1LL * x) % M;
		y /= 2;
	}
	return res;
}

int main() {
	int tt;
	cin >> tt;
	while (tt--) {
		int n, m, k;
		cin >> n >> m >> k;
		vector<vector<int>> f(n + 1, vector<int>(n + 1, 0));
		int pw2 = 1;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j <= n; j++) {
				if (j == 0) {
					f[i][j] = (pw2 * 1LL * i) % M;
				} else {
					f[i][j] = (f[i - 1][j - 1] + f[i - 1][j]) % M;
				}
			}
			if (i < n) pw2 = (pw2 + pw2) % M;
		}
		int res = (f[n][n - m] * 1LL * pw(pw2, M - 2)) % M;
		res = (res * 1LL * k) % M;
		cout << res << "\n";
	}
	return 0;
}