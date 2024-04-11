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

const int MOD = (int)1e9 + 7;
int mult(int x, int y) {
	return ((ll)x * y) % MOD;
}

const int LOG = 19;
const int N = 500500;
//const int N = 555;
int n;
int h[N];
int par[N][LOG];
vector<int> g[N];
pii pp[2 * N];
int m;
int deg[N];
bool st[N];
bool used[4 * N];
int q[N];
int f[N];
pii idToEdge[4 * N];
int S;
int nxt[4 * N];
int prv[4 * N];

int getId(int v, int u) {
	return lower_bound(idToEdge, idToEdge + S, mp(v, u)) - idToEdge;
}

void dfs(int v) {
	for (int u : g[v]) {
		if (h[u] != -1) continue;
		h[u] = h[v] + 1;
		par[u][0] = v;
		for (int k = 0; k < LOG - 1; k++) {
			if (par[u][k] == -1) break;
			par[u][k + 1] = par[par[u][k]][k];
		}
		dfs(u);
	}
}

int up(int v, int dh) {
	for (int k = 0; k < LOG; k++)
		if ((dh >> k) & 1)
			v = par[v][k];
	return v;
}
int LCA(int v, int u) {
	if (h[v] > h[u]) swap(v, u);
	u = up(u, h[u] - h[v]);
	if (v == u) return v;
	for (int k = LOG - 1; k >= 0; k--) {
		if (par[v][k] != par[u][k]) {
			v = par[v][k];
			u = par[u][k];
		}
	}
	return par[v][0];
}

vector<int> getPath(int v, int u) {
	int w = LCA(v, u);
	vector<int> p1, p2;
	p1.push_back(-1);
	p2.push_back(-2);
	while(v != w) {
		p1.push_back(v);
		v = par[v][0];
	}
	while(u != w) {
		p2.push_back(u);
		u = par[u][0];
	}
	p1.push_back(w);
	while(!p2.empty()) {
		p1.push_back(p2.back());
		p2.pop_back();
	}
	return p1;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int v, u;
		scanf("%d%d", &v, &u);
		v--;u--;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	for (int v = 0; v < n; v++) {
		idToEdge[S++] = mp(v, -1);
		idToEdge[S++] = mp(v, -2);
		for (int u : g[v])
			idToEdge[S++] = mp(v, u);
	}
	sort(idToEdge, idToEdge + S);
	for (int i = 0; i < S; i++) {
		nxt[i] = -1;
		prv[i] = -1;
	}
	for (int i = 0; i < n; i++) {
		h[i] = -1;
		for (int j = 0; j < LOG; j++)
			par[i][j] = -1;
	}
	h[0] = 0;
	dfs(0);
	for (int v = 0; v < n; v++)
		deg[v] = (int)g[v].size();
	for (int i = 0; i < n; i++)
		st[i] = true;
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		x--;
		q[i] = x;
		st[x] = false;
		if (x == -1) continue;
		if (i == x) {
			printf("0\n");
			return 0;
		}
		vector<int> path = getPath(i, x);
//		for (int x : path)
//			eprintf("%d ", x);
//		eprintf("\n");
		for (int j = 1; j < (int)path.size() - 1; j++) {
			deg[path[j]]--;
			int V = getId(path[j], path[j - 1]), U = getId(path[j], path[j + 1]);
			if (nxt[V] != -1 || prv[U] != -1) {
				printf("0\n");
				return 0;
			}
			nxt[V] = U;
			prv[U] = V;
		}
	}
	for (int v = 0; v < n; v++) {
		if (!st[v]) continue;
		int x = v;
		while(x != -1) {
			used[x] = 1;
			x = q[x];
		}
	}
	int V = -1;
	for (int i = 0; i < n; i++)
		if (!used[i])
			V = i;
	if (V != -1) {
		int len = 0;
		int x = V;
		do {
			len++;
			x = q[x];
		} while(x != V);
		if (len != n) {
			printf("0\n");
			return 0;
		}
	}


//	eprintf("here\n");
	for (int i = 0; i < S; i++)
		used[i] = false;
	for (int v = 0; v < n; v++) {
//		if (deg[v] == 0) continue;
		int x = getId(v, -1);
		if (prv[x] != -1) throw;
		while(x != -1) {
			used[x] = 1;
			x = nxt[x];
		}
	}
//	eprintf("here\n");
	for (int i = 0; i < S; i++) {
		if (used[i]) continue;
		int v = idToEdge[i].first;
		if (used[getId(v, -2)]) {
			printf("0\n");
			return 0;
		}
	}
	for (int i = 0; i < S; i++) {
		if (prv[i] != -1) continue;
		if (used[i]) continue;
		int x = i;
		while(x != -1) {
			used[x] = 1;
			x = nxt[x];
		}
	}
	for (int i = 0; i < S; i++) {
		if (!used[i]) {
			printf("0\n");
			return 0;
		}
	}

	f[0] = 1;
	for (int i = 1; i <= n; i++)
		f[i] = mult(f[i - 1], i);
	int ans = 1;
	for (int i = 0; i < n; i++)
		if (deg[i] > 1)
			ans = mult(ans, f[deg[i]]);
	printf("%d\n", ans);

	return 0;
}