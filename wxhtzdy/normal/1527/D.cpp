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
#include <bitset>
#include <array>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) {fprintf(stderr, __VA_ARGS__);fflush(stderr);}
#else
	#define eprintf(...) 42
#endif

using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
template<typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll myRand(ll B) {
	return (ull)rng() % B;
}

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

clock_t startTime;
double getCurrentTime() {
	return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

const int N = 200050;
const int L = 20;
int Q = 0;
int n;
vector<int> g[N];
int par[N][L];
int dep[N];
int sz[N];
ll ans[N];
pii fe = mp(-1, -1);

void dfs(int v, int pv) {
	par[v][0] = pv;
	for (int j = 1; j < L; j++)
		par[v][j] = par[par[v][j - 1]][j - 1];
	dep[v] = dep[pv] + 1;
	sz[v] = 1;
	for (int u : g[v]) {
		if (u == pv) continue;
		dfs(u, v);
		sz[v] += sz[u];
	}
}

int LCA(int u, int v) {
	if (dep[u] < dep[v]) swap(u, v);
	int dv = dep[u] - dep[v];
	for (int i = L - 1; i >= 0; i--)
		if (dv >> i & 1)
			u = par[u][i];
	if (u == v)
		return u;
	for (int i = L - 1; i >= 0; i--)
		if (par[u][i] != par[v][i])
			u = par[u][i], v = par[v][i];
	return par[u][0];
}

bool is_anc(int x, int y) {
	return LCA(x, y) == x;
}

bool isOnPath(int u, int v, int x) {
	int lca = LCA(u, v);
	return is_anc(lca, x) && (is_anc(x, u) || is_anc(x, v));
}

int lift(int v, int dv) {
	for (int i = L - 1; i >= 0; i--)
		if (dv >> i & 1)
			v = par[v][i];
	return v;
}

void solve() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) g[i].clear(), sz[i] = 0;
	for (int i = 1; i < n; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
		if (fe == mp(-1, -1))
			fe = mp(u, v);
	}
	dfs(0, N - 1);
	for (int i = 0; i <= n; i++)
		ans[i] = 0;
	for (int v : g[0])
		ans[0] += sz[v] * 1ll * (sz[v] - 1) / 2;
	ll S = 1;
	for (int v : g[0]) {
		int SZ = sz[v];
		if (LCA(v, 1) == v) SZ -= sz[1];
		ans[1] += SZ * S;
		S += SZ;
	}
	int L = 0, R = 0;
	for (int i = 1; i < n; i++) {
		if ((!is_anc(i, L) && !is_anc(L, i)) && (!is_anc(i, R) && !is_anc(R, i)))
			break;
		if (is_anc(L, i))
			L = i;
		else if (!is_anc(i, L) && is_anc(R, i))
			R = i;
		if (LCA(L, R) != 0)
			break;
		if (i + 1 < n && isOnPath(L, R, i + 1))
			continue;
		int szL = sz[L], szR = sz[R];
		if (i + 1 < n && is_anc(L, i + 1) && (L != 0 || !is_anc(lift(R, dep[R] - 2), i + 1)))
			szL -= sz[i + 1];
		if (i + 1 < n && is_anc(R, i + 1) && (R != 0 || !is_anc(lift(L, dep[L] - 2), i + 1)))
			szR -= sz[i + 1];
		if (L == 0)
			szL -= sz[lift(R, dep[R] - 2)];
		if (R == 0)
			szR -= sz[lift(L, dep[L] - 2)];
		ans[i + 1] = szL * 1ll * szR;
	}
	for (int i = 0; i <= n; i++) {
		/*Q++;
		if (Q == 4852 && fe == mp(90, 72)) printf("%d ", i);
		else*/ printf("%lld ", ans[i]);
	}
	printf("\n");
}

int main()
{
	startTime = clock();

	int t;
	scanf("%d", &t);
	while(t--) solve();

	return 0;
}