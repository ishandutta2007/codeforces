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

int calcC(vector<int> &fact, vector<int> &rev, int n, int m) {
	if ((m < 0) || (m > n)) return 0;
	int res = (fact[n] * 1LL * rev[m]) % M;
	res = (res * 1LL * rev[n - m]) % M;
	return res;
}

int main() {
	int tt;
	cin >> tt;
	while (tt--) {
		int n, m, k;
		cin >> n >> m >> k;
		vector<int> fact(n + 1);
		vector<int> rev(n + 1);
		fact[0] = 1;
		rev[0] = 1;
		for (int i = 1; i <= n; i++) {
			fact[i] = (fact[i - 1] * 1LL * i) % M;
			rev[i] = pw(fact[i], M - 2);
		}
		int pw2 = 1;
		int res = 0;
		for (int i = 1; i < n; i++) {
			int fi0 = (pw2 * 1LL * i) % M;
			// (i + 1, 1) -> (n, n - m)
			int cnt = calcC(fact, rev, n - i - 1, n - m - 1);
			res = (res + cnt * 1LL * fi0) % M;
			pw2 = (pw2 + pw2) % M;
		}
		if (n == m) {
			res = (pw2 * 1LL * n) % M;
		}
		res = (res * 1LL * pw(pw2, M - 2)) % M;
		res = (res * 1LL * k) % M;
		cout << res << "\n";
	}
	return 0;
}