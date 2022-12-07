#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; i >= a; i--)
 
using namespace std;

const int P = 1e9 + 7;

int n, dp[1 << 20][20][2];

void add(int &a, int b) {
	a = (a + b) % P;
}

int f(int a, int b) {
	int res = n / (1 << a);
	if (b) res /= 3;
	return res;
}

int main() {
	cin >> n;
	int m = log2(n);
	dp[1][m][0] = 1;
	if ((1 << m) * 3 <= 2 * n)
		dp[1][m - 1][1] = 1;
	rep(i, 1, n - 1)
		rep(a, 0, 19)
			rep(b, 0, 1) {
				// dont change
				add(dp[i + 1][a][b], 1ll * dp[i][a][b] * (f(a, b) - i) % P);
				// hit 2
				if (a)
				add(dp[i + 1][a - 1][b], 1ll * dp[i][a][b] * (f(a - 1, b) - f(a, b)) % P);
				// hit 3
				if (b)
				add(dp[i + 1][a][b - 1], 1ll * dp[i][a][b] * (f(a, b - 1) - f(a, b)) % P);
			}
	cout << dp[n][0][0] << "\n";
	return 0;
}