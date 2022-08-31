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

const ll MOD = 998244353;
ll add(ll x, ll y) {
	x += y;
	if (x >= MOD) return x - MOD;
	return x;
}
ll mult(ll x, ll y) {
	return (x * y) % MOD;
}

const int N = 300300;
vector<int> g[N];
int col[N];
int n, m;
ll A1, A2;

bool dfs(int v) {
	if (col[v] == 0)
		A1 = add(A1, A1);
	else
		A2 = add(A2, A2);
	for (int u : g[v]) {
		if (col[u] == -1) {
			col[u] = col[v] ^ 1;
			if (!dfs(u)) return false;
		} else if (col[v] == col[u]) return false;
	}
	return true;
}

ll solve(int v) {
	A1 = A2 = 1;
	col[v] = 0;
	if (!dfs(v)) return 0;
	return add(A1, A2);
}

void solve() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		g[i].clear();
		col[i] = -1;
	}
	while(m--) {
		int v, u;
		scanf("%d%d", &v, &u);
		v--;u--;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	ll ans = 1;
	for (int i = 0; i < n; i++) {
		if (col[i] == -1)
			ans = mult(ans, solve(i));
	}
	printf("%lld\n", ans);
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int t;
	scanf("%d", &t);
	while(t--) solve();

	return 0;
}