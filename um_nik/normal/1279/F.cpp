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
#include <chrono>
#include <random>
#include <queue>
#include <bitset>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
typedef long double ld;
#define mp make_pair
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = (int)1e6 + 77;
const ll INF = (ll)1e17;
pli dp[N];
int par[N];
int a[N];
char s[N];
int n, m, l;

pli solve(ll lambda) {
	for (int i = 0; i <= n; i++)
		dp[i] = mp((ll)N, N);
	dp[0] = mp(0LL, 0);
	for (int i = 0; i < n; i++) {
		int j = min(n, i + l);
		pli w = dp[i];
		w.second++;
		w.first += lambda;
		dp[j] = min(dp[j], w);
		w = dp[i];
		if (a[i] == 1) w.first++;
		dp[i + 1] = min(dp[i + 1], w);
	}
	return dp[n];
}

ll solve() {
	if ((ll)m * l >= n) return 0;
	ll L = -1, R = (ll)N;
	while(R - L > 1) {
		ll X = (L + R) / 2;
		if (solve(X).second <= m)
			R = X;
		else
			L = X;
	}
	pli ans = solve(R);
	return ans.first - R * m;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d%d", &n, &m, &l);
	scanf("%s", s);
	for (int i = 0; i < n; i++) {
		if ('A' <= s[i] && s[i] <= 'Z')
			a[i] = 1;
		else
			a[i] = 0;
	}
	ll ans = INF;
	ans = min(ans, solve());
	for (int i = 0; i < n; i++)
		a[i] ^= 1;
	ans = min(ans, solve());
	printf("%lld\n", ans);

	return 0;
}