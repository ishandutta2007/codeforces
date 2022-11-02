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

int ts[100009 * 44], L[100009 * 44], R[100009 * 44], tn;
int build(int le, int ri) {
	int id = tn++;
	if(le != ri) {
		int mi = (le + ri) / 2;
		L[id] = build(le, mi);
		R[id] = build(mi + 1, ri);
	}
	return id;
}

int add(int oid, int le, int ri, int x) {
	int id = tn++;
	ts[id] = ts[oid] + 1;
	if(le == ri) return id;
	L[id] = L[oid];
	R[id] = R[oid];
	int mi = (le + ri) / 2;
	if(x <= mi) L[id] = add(L[oid], le, mi, x);
	else R[id] = add(R[oid], mi + 1, ri, x);
	return id;
}

vector<int> adj[100009];
vector<int> ps[100009];
int lc[100009][20], nv[100009], num[100009];
int root[100009], n, m;
void dfs(int u, int p, int nv) {
	::nv[u] = nv;
	lc[u][0] = p;
	for(int i = 1; i < 20; i++)
		lc[u][i] = lc[lc[u][i-1]][i-1];
	root[u] = root[p];
	for(int x : ps[u])
		root[u] = add(root[u], 0, m - 1, x);
	num[u] = ps[u].size() + num[lc[u][0]];
	for(int v : adj[u])
		if(v != p)
			dfs(v, u, nv + 1);
}

int lca(int u, int v) {
	if(nv[u] > nv[v]) swap(u, v);
	if(nv[u] < nv[v])
		for(int i = 19; i >= 0; i--)
			if(nv[lc[v][i]] >= nv[u])
				v = lc[v][i];
	if(u == v) return u;
	for(int i = 19; i >= 0; i--)
		if(lc[u][i] != lc[v][i])
			u = lc[u][i], v = lc[v][i];
	return lc[u][0];
}

int get(int idu, int idv, int idx, int idy, int le, int ri, int x) {
	if(le == ri) return le;
	int mi = (le + ri) / 2;
	int val = ts[L[idv]] + ts[L[idu]] - ts[L[idx]] - ts[L[idy]];
	//printf("search %d -> val %d\n", x, val);
	if(x <= val) return get(L[idu], L[idv], L[idx], L[idy], le, mi, x);
	else return get(R[idu], R[idv], R[idx], R[idy], mi + 1, ri, x - val);
}
int c[100009];
int main() {
	int q, v, u, a, b, i, j;
	scanf("%d %d %d", &n, &m, &q);
	for(i = 0; i < n - 1; i++) {
		scanf("%d %d", &a, &b); a--; b--;
		adj[a].pb(b); adj[b].pb(a);
	}
	for(i = 0; i < m; i++) {
		scanf("%d", &c[i]);
		ps[--c[i]].pb(i);
	}
	root[0] = build(0, m - 1);
	dfs(0, 0, 0);
	for(i = 0; i < q; i++) {
		scanf("%d %d %d", &v, &u, &a); u--; v--;
		int x = lca(u, v);
		int y = lc[x][0];
		if(x == 0) y = 100006;
		//printf("u=%d v=%d lca=%d lcap=%d\n", u, v, x, y);
		a = min(a, num[u] + num[v] - num[x] - num[y]);
		printf("%d", a);
		for(j = 0; j < a; j++)
			printf(" %d", get(root[u], root[v], root[x], root[y], 0, m - 1, j + 1) + 1);
		putchar('\n');
	}
}