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

const ll MOD = (ll)1e9 + 7;
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

const int N = 3030;
ll dp[N][N];
ll rev[N];
vector<int> g[N];
int p[N];
int n;

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	ll P;

	rev[1] = 1;
	for (ll x = 2; x < N; x++)
		rev[x] = sub(0, mult(MOD / x, rev[MOD % x]));

	scanf("%d%lld", &n, &P);
	for (int i = 1; i < n; i++) {
		scanf("%d", &p[i]);
		p[i]--;
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j <= n; j++)
			dp[i][j] = 1;
	for (int v = n - 1; v >= 0; v--) {
		dp[v][0] = 0;
		for (int i = 1; i <= n; i++)
			dp[v][i] = add(dp[v][i], dp[v][i - 1]);
		if (v == 0) break;
		for (int i = 0; i <= n; i++)
			dp[p[v]][i] = mult(dp[p[v]][i], dp[v][i]);
	}

	ll ANS = 0;
	for (int i = 0; i <= n; i++) {
		ll ans = dp[0][i];
		for (int j = 0; j <= n; j++) {
			if (j == i) continue;
			ans = mult(ans, sub(P, j));
			ans = mult(ans, rev[abs(i - j)]);
			if (i < j)
				ans = sub(0, ans);
		}
		ANS = add(ANS, ans);
	}
	printf("%lld\n", ANS);

	return 0;
}