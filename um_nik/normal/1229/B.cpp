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

ll gcd(ll x, ll y) {
	return y == 0 ? x : gcd(y, x % y);
}

const int N = 100100;
vector<int> g[N];
vector<pli> a[N];
int n;
ll x[N];

void dfs(int v, int par) {
	if (par != -1) {
		for (pli t : a[par]) {
			ll y = gcd(t.first, x[v]);
			if (a[v].empty() || a[v].back().first != y) {
				a[v].push_back(mp(y, t.second));
			} else {
				a[v].back().second += t.second;
			}
		}
	}
	if (a[v].empty() || a[v].back().first != x[v]) {
		a[v].push_back(mp(x[v], 1));
	} else {
		a[v].back().second++;
	}
	for (int u : g[v]) {
		if (u == par) continue;
		dfs(u, v);
	}
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%lld", &x[i]);
	for (int i = 1; i < n; i++) {
		int v, u;
		scanf("%d%d", &v, &u);
		v--;u--;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	dfs(0, -1);
	ll ans = 0;
	for (int v = 0; v < n; v++)
		for (pli t : a[v]) {
			ans = (ans + t.first * t.second) % MOD;
		}
	printf("%lld\n", ans);

	return 0;
}