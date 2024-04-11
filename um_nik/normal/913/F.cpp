#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

const ll MOD = 998244353;
ll add(ll x, ll y) {
	x += y;
	if (x >= MOD) return x - MOD;
	return x;
}
ll sub(ll x, ll y) {
	x -= y;
	if (x < 0) return x + MOD;
	return x;
}
ll mult(ll x, ll y) {
	return (x * y) % MOD;
}
ll bin_pow(ll x, ll p) {
	if (p == 0) return 1;
	if (p & 1) return mult(x, bin_pow(x, p - 1));
	return bin_pow(mult(x, x), p / 2);
}
ll rev(ll x) {
	return bin_pow(x, MOD - 2);
}

const int N = 2020;
ll pw[2][N];
ll sc[N];
ll dp[N][N];
ll ans[N];

void solve() {

	ans[1] = 0;
	sc[1] = 1;
	dp[1][0] = dp[1][1] = 1;
	for (int n = 2; n < N; n++) {
		
		for (int k = 0; k < n; k++) {
			dp[n][k] = add(dp[n][k], mult(dp[n - 1][k], pw[0][k]));
			dp[n][k + 1] = add(dp[n][k + 1], mult(dp[n - 1][k], pw[1][n - k - 1]));
		}
		
		sc[n] = 1;
		for (int m = 1; m < n; m++) {
			sc[n] = sub(sc[n], mult(dp[n][m], sc[m]));
		}

		ans[n] = mult(sc[n], n * (n - 1) / 2);
		for (int m = 1; m < n; m++) {
			ll val = m * (m - 1) / 2 + m * (n - m);
			val = add(val, ans[m]);
			val = add(val, ans[n - m]);
			ans[n] = add(ans[n], mult(val, mult(sc[m], dp[n][m])));
		}
		ans[n] = mult(ans[n], rev(sub(1, sc[n])));

	}

}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int n;
	ll A, B;
	scanf("%d%lld%lld", &n, &A, &B);
	pw[0][0] = pw[1][0] = 1;
	pw[0][1] = mult(A, rev(B));
	pw[1][1] = sub(1, pw[0][1]);
	for (int k = 0; k < 2; k++)
		for (int i = 2; i < N; i++)
			pw[k][i] = mult(pw[k][i - 1], pw[k][1]);

	solve();

	printf("%lld\n", ans[n]);

	return 0;
}