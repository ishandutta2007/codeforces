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

const ll C = (ll)1e9 + 2;
//const ll C = 100;
const int N = 100100;
int sz;
int l[N], r[N], g[N];
ll a[4];
ll dp[N][4];

void addSegm(int L, int R, int G) {
	if (sz > 0 && g[sz - 1] == G) {
		r[sz - 1] = R;
		return;
	}
	l[sz] = L;
	r[sz] = R;
	g[sz] = G;
	sz++;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	addSegm(0, 3, 0);
	ll cur = 3;
	int p1 = 0, p2 = 0;
	while(cur <= C) {
//		cerr << cur << endl;
		ll y = cur / 3;
		while(y >= r[p1]) p1++;
		while(cur - y >= r[p2]) p2++;
		ll nxt = min(3LL * r[p1], 3LL * r[p2] / 2) - 5;
		if (nxt < cur) nxt = cur;
		while(true) {
			y = nxt / 3;
			if (y >= r[p1] || nxt - y >= r[p2]) break;
			nxt++;
		}
		int G = 0;
		while(G == g[p1] || G == g[p2]) G++;
		addSegm(cur, nxt, G);
		cur = nxt;
	}
//	cerr << sz << endl;

	int n, p;
	scanf("%d%d", &n, &p);
	for (int i = 0; i < sz; i++) {
		if (l[i] >= p) break;
		int L = max(1, l[i]), R = min(p, r[i]);
		swap(L, R);
		L = p - L;
		R = p - R;
		a[g[i]] += (ll)R * (R + 1) / 2;
		a[g[i]] -= (ll)L * (L + 1) / 2;
	}
	for (int i = 0; i < 4; i++)
		a[i] %= MOD;
//	for (int i = 0; i < 4; i++)
//		cerr << a[i] << " ";
//	cerr << endl;
	dp[0][0] = 1;
	for (int i = 0; i < n; i++)
		for (int x = 0; x < 4; x++)
			for (int y = 0; y < 4; y++)
				dp[i + 1][x ^ y] = add(dp[i + 1][x ^ y], mult(dp[i][x], a[y]));
	ll ans = 0;
	for (int i = 1; i < 4; i++)
		ans = add(ans, dp[n][i]);
	printf("%lld\n", ans);

	return 0;
}