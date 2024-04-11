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
ll mult(ll x, ll y) {
	return (x * y) % MOD;
}

const int N = 100100;
const int LOG = 17;
const int C = (int)1e7 + 10;
const int M = (int)1e6 + 3;
int d[C];
int pr[M];
int prSz;
vector<pii> nodesForPrime[M];
vector<pii> queryForPrime[M];
vector<ll> primePowers[M];

vector<int> g[N];
int n;
int par[N][LOG];
int h[N];
int T1, T2;
int t[N][3];

void dfs(int v) {
	t[v][0] = T1++;
	for (int u : g[v]) {
		if (h[u] != -1) continue;
		h[u] = h[v] + 1;
		par[u][0] = v;
		for (int k = 0; k < LOG - 1; k++) {
			int w = par[u][k];
			if (w != -1)
				par[u][k + 1] = par[w][k];
		}
		dfs(u);
	}
	t[v][1] = T1;
	t[v][2] = T2++;
}

int up(int v, int dh) {
	for (int k = LOG - 1; k >= 0; k--) {
		if (dh < (1 << k)) continue;
		dh -= 1 << k;
		v = par[v][k];
	}
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

int fenv[2][N];
void fenvAdd(int k, int r, int dx) {
	for(; r < n; r |= r + 1)
		fenv[k][r] += dx;
}
int fenvGet(int k, int r) {
	int res = 0;
	for (; r >= 0; r = (r & (r + 1)) - 1)
		res += fenv[k][r];
	return res;
}

int m;
int qu[N][4];
ll ANS[N];

void precalc() {
	for (int i = 1; i < C; i++)
		d[i] = -1;
	for (int x = 2; x < C; x++) {
		if (d[x] != -1) continue;
		pr[prSz] = x;
		for (int y = x; y < C; y += x)
			if (d[y] == -1)
				d[y] = prSz;
		primePowers[prSz].push_back(1);
		prSz++;
	}
}

void addPrimeNode(int p, int id, int pw) {
//	eprintf("add prime node %d %d %d\n", pr[p], id, pw);
	nodesForPrime[p].push_back(mp(pw, id));
	for (int i = 1; i <= pw; i++) {
		primePowers[p].push_back(mult(primePowers[p].back(), pr[p]));
	}
}
void addPrimeQuery(int p, int id, int pw) {
//	eprintf("add prime query %d %d %d\n", pr[p], id, pw);
	queryForPrime[p].push_back(mp(pw, id));
}

void read() {
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int v, u;
		scanf("%d%d", &v, &u);
		v--;u--;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	for (int v = 0; v < n; v++) {
		h[v] = -1;
		for (int i = 0; i < LOG; i++)
			par[v][i] = -1;
	}
	h[0] = 0;
	dfs(0);
//	eprintf("times:\n");
//	for (int v = 0; v < n; v++)
//		eprintf("%d %d %d\n", t[v][0], t[v][1], t[v][2]);
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		while(x > 1) {
			int p = d[x];
			int pw = 0;
			while(d[x] == p) {
				pw++;
				x /= pr[p];
			}
			addPrimeNode(p, i, pw);
		}
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		ANS[i] = 1;
		int v, u, x;
		scanf("%d%d%d", &v, &u, &x);
		v--;u--;
		qu[i][0] = v;
		qu[i][1] = u;
		qu[i][2] = LCA(v, u);
		qu[i][3] = par[qu[i][2]][0];
//		eprintf("%d %d %d %d\n", qu[i][0], qu[i][1], qu[i][2], qu[i][3]);
		while(x > 1) {
			int p = d[x];
			int pw = 0;
			while(d[x] == p) {
				pw++;
				x /= pr[p];
			}
			addPrimeQuery(p, i, pw);
		}
	}
	for (int i = 0; i < prSz; i++) {
		sort(nodesForPrime[i].begin(), nodesForPrime[i].end());
		reverse(nodesForPrime[i].begin(), nodesForPrime[i].end());
		sort(queryForPrime[i].begin(), queryForPrime[i].end());
	}
}

void addInV(int v, int dx) {
	fenvAdd(0, t[v][0], dx);
	fenvAdd(1, t[v][2], dx);
}

int getSumV(int v) {
	if (v == -1) return 0;
	return fenvGet(0, t[v][1] - 1) - fenvGet(1, t[v][2] - 1);
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	precalc();
	read();

	for (int id = 0; id < m; id++) {
		int it = 0;
		int k = 0;
		while(it < (int)queryForPrime[id].size()) {
			k++;
			for (int i = 0; i < (int)nodesForPrime[id].size() && nodesForPrime[id][i].first >= k; i++) {
				addInV(nodesForPrime[id][i].second, 1);
			}
			while(it < (int)queryForPrime[id].size() && queryForPrime[id][it].first == k) {
				int s = queryForPrime[id][it].second;
				it++;
				int pw = 0;
				pw += getSumV(qu[s][0]);
				pw += getSumV(qu[s][1]);
				pw -= getSumV(qu[s][2]);
				pw -= getSumV(qu[s][3]);
				ANS[s] = mult(ANS[s], primePowers[id][pw]);
			}
		}
		while(k > 0) {
			for (int i = 0; i < (int)nodesForPrime[id].size() && nodesForPrime[id][i].first >= k; i++) {
				addInV(nodesForPrime[id][i].second, -1);
			}
			k--;
		}
	}

	for (int i = 0; i < m; i++)
		printf("%lld\n", ANS[i]);

	return 0;
}