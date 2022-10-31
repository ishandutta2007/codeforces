#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
const int N = 100009;
#define all(v) v.begin(), v.end()
ll e[N], A[N];
int lc[N][19], nv[N], f[N];
vector<int> adj[N];
int n;
int dfs(int u, int p, int nv) {
	::nv[u] = nv;
	lc[u][0] = p;
	for(int i = 1; i < 19; i++)
		lc[u][i] = lc[lc[u][i - 1]][i - 1];
	if(u) adj[u].erase(search_n(all(adj[u]), 1, p));
	f[u] = 1;
	for(int v : adj[u]) {
		f[u] += dfs(v, u, nv + 1);
		e[u] += e[v] + ll(f[v]);
	}
	return f[u];
}

int dfs2(int u, int p) {
	if(u) A[u] = A[p] + ll(n - 2 * f[u]);
	else A[u] = e[u];
	for(int v : adj[u])
		dfs2(v, u);
}

int lca(int u, int v) {
	if(nv[u] < nv[v]) swap(u, v);
	int x = nv[u] - nv[v];
	for(int i = 0; i < 19; i++)
		if((1 << i) & x)
			u = lc[u][i];
	if(u == v) return v;
	for(int i = 18; i >= 0; i--)
		if(lc[u][i] != lc[v][i])
			u = lc[u][i], v = lc[v][i];
	return lc[u][0];
}

int main() {
	int i, m, a, b;
	scanf("%d %d", &n, &m);
	for(i = 0; i < n - 1; i++) {
		scanf("%d %d", &a, &b); a--; b--;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	dfs(0, 0, 0);
	dfs2(0, 0);
	for(i = 0; i < m; i++) {
		scanf("%d %d", &a, &b); a--; b--;
		if(nv[a] > nv[b]) swap(a, b);
		int c = lca(a, b);
		if(c != a) printf("%.10f\n", nv[a] + nv[b] + 1 - 2*nv[c] + double(e[a]) / f[a] + double(e[b]) / f[b]);
		else {
			double r = nv[b] - nv[a] + 1 + double(e[b]) / f[b];
			int x = nv[b] - nv[a] - 1;
			for(int i = 0; i < 19; i++)
				if((1 << i) & x)
					b = lc[b][i];
			r += double(A[a] - e[b] - ll(f[b])) / (n - f[b]);
			printf("%.10f\n", r);
		}
	}
}