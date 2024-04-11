#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; i >= a; i--)
 
using namespace std;
 
const int P = 1e9 + 7;

long long power(long long a, long long b) {
	long long res = 1;
	for (; b; b /= 2, a = a * a % P)
		if (b & 1) res = res * a % P;
	return res;
}

int n, k;
long long fac[405], inv[405], dp[205][205][405];
map<pair<int, int>, int> m;

long long C(int N, int K) {
	if (N < K) return 0;
	if (m.count(make_pair(N, K)))
		return m[{N, K}];
	long long ans = 1;
	rep(i, N - K + 1, N)
		ans = ans * i % P;
	return m[{N, K}] = ans * inv[K] % P;
}
 
int main() {
	cin >> n >> k;
	fac[0] = inv[0] = 1;
	rep(i, 1, 400) {
		fac[i] = fac[i - 1] * i % P;
		inv[i] = power(fac[i], P - 2);
	}
	dp[1][0][0] = 1;
	rep(i, 1, k + 1)
		rep(a, 0, k)
			rep(b, 0, 2 * k) {
				if (!dp[i][a][b]) continue;
				rep(cnt, 0, k) {
					int na = a + cnt * i;
					int nb = b + cnt * (i + 1);
					if (na > k || nb > 2 * k) 
						break;
					int cur = C(n - b, cnt * (i + 1)) *
							  fac[cnt * (i + 1)] % P *
							  power(inv[i + 1], cnt) % P *	
							  inv[cnt] % P *
							  power(fac[i], cnt) % P;
					dp[i + 1][na][nb] = (dp[i + 1][na][nb] + dp[i][a][b] * cur) % P;
				}
			}
	rep(i, 1, k) {
		long long ans = 0;
		rep(a, 0, i)
			rep(b, 0, min(2 * k, n))
				if (a % 2 == i % 2)
					ans = (ans + dp[k + 1][a][b]) % P;
		cout << ans << " ";
	}
	return 0;
}