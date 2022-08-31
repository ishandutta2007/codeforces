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
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
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

const int N = 500500;
int n, m, k;
ll a[N];
ll p2[N];
map<ll, vector<pii>> G;
int par[N];
int sz[N];

map<int, int> toId;
int getId(int v) {
	if (toId.count(v) > 0) return toId[v];
	toId[v] = m;
	par[m] = -1;
	sz[m] = 1;
	return m++;
}

int getPar(int v) {
	return par[v] == -1 ? v : par[v] = getPar(par[v]);
}
bool unite(int v, int u) {
	v = getPar(v);
	u = getPar(u);
	if (v == u) return false;
	if (sz[v] < sz[u]) swap(v, u);
	sz[v] += sz[u];
	par[u] = v;
	return true;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	p2[0] = 1;
	for (int i = 1; i < N; i++) {
		p2[i] = add(p2[i - 1], p2[i - 1]);
	}
	scanf("%d%d%d", &n, &m, &k);
	ll ans = p2[n + k];
	for (int i = 0; i < n; i++)
		scanf("%lld", &a[i]);
	while(m--) {
		int v, u;
		scanf("%d%d", &v, &u);
		v--;u--;
		G[a[v] ^ a[u]].push_back(mp(v, u));
	}
	for (auto t : G) {
		vector<pii> g = t.second;
		m = 0;
		toId.clear();
		int C = n;
		for (pii s : g) {
			int v = getId(s.first), u = getId(s.second);
			if (unite(v, u)) C--;
		}
		ans = sub(ans, p2[n]);
		ans = add(ans, p2[C]);
	}
	printf("%lld\n", ans);

	return 0;
}