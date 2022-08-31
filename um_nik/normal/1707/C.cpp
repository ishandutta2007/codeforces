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

const int LOG = 18;
const int N = 200200;
int par[N];
int sz[N];
vector<int> g[N];
int n, m, k;
pii ed[N];
int T;
int t[N][2];
int h[N];
int pp[N][LOG];
int a[N];

int getPar(int v) {
	return (par[v] == v ? v : par[v] = getPar(par[v]));
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

void dfs(int v, int par) {
	t[v][0] = T++;
	for (int u : g[v]) if (u != par) {
		h[u] = h[v] + 1;
		pp[u][0] = v;
		for (int k = 0; k < LOG - 1; k++)
			pp[u][k + 1] = pp[pp[u][k]][k];
		dfs(u, v);
	}
	t[v][1] = T;
}

int up(int v, int dh) {
	for (int k = 0; k < LOG; k++)
		if ((dh >> k) & 1)
			v = pp[v][k];
	return v;
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		par[i] = i;
		sz[i] = 1;
	}
	for (int i = 0; i < m; i++) {
		int v, u;
		scanf("%d%d", &v, &u);
		v--;u--;
		if (unite(v, u)) {
			g[v].push_back(u);
			g[u].push_back(v);
		} else {
			ed[k++] = mp(v, u);
		}
	}
	dfs(0, -1);
	for (int i = 0; i < k; i++) {
		int v = ed[i].first, u = ed[i].second;
		if (t[v][0] > t[u][0]) swap(v, u);
		if (t[v][1] >= t[u][1]) {
			int w = up(u, h[u] - h[v] - 1);
			a[0]++;
			a[t[w][0]]--;
			a[t[u][0]]++;
			a[t[u][1]]--;
			a[t[w][1]]++;
			a[n]--;
		} else {
			a[t[v][0]]++;
			a[t[v][1]]--;
			a[t[u][0]]++;
			a[t[u][1]]--;
		}
	}
	for (int i = 0; i < n; i++)
		a[i + 1] += a[i];
	for (int v = 0; v < n; v++)
		if (a[t[v][0]] == k)
			printf("1");
		else
			printf("0");
	printf("\n");

	return 0;
}