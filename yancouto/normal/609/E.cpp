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
const int N = 200009;
int S[N], sz[N];
int find(int i) {
	if(S[S[i]] != S[i]) S[i] = find(S[i]);
	return S[i];
}
inline void join(int a, int b) {
	if((a = find(a)) == (b = find(b))) return;
	if(sz[a] < sz[b]) swap(a, b);
	sz[a] += sz[b];
	S[b] = a;
}


vector<pii> adj[N];
int nv[N], mx[N][20], pai[N][20];
void dfs(int u, int p, int val, int nv) {
	::nv[u] = nv;
	pai[u][0] = p;
	mx[u][0] = val;
	for(int i = 1; i < 20; i++)
		pai[u][i] = pai[pai[u][i - 1]][i - 1],
		mx[u][i] = max(mx[u][i - 1], mx[pai[u][i - 1]][i - 1]);
	for(pii e : adj[u])
		if(e.fst != p)
			dfs(e.fst, u, e.snd, nv + 1);
}

ll lca(int u, int v) {
	if(nv[u] > nv[v]) swap(u, v);
	int val = INT_MIN;
	for(int i = 19; i >= 0; i--)
		if(nv[pai[v][i]] >= nv[u]) {
			val = max(val, mx[v][i]);
			v = pai[v][i];
		}
	if(u == v) return val;
	for(int i = 19; i >= 0; i--)
		if(pai[u][i] != pai[v][i]) {
			val = max(val, max(mx[u][i], mx[v][i]));
			u = pai[u][i];
			v = pai[v][i];
		}
	return max(val, max(mx[v][0], mx[u][0]));
}

int u[N], v[N], w[N], p[N];
bool got[N];
int main() {
	int i, n, m;
	scanf("%d %d", &n, &m);
	for(i = 0; i < m; i++) {
		scanf("%d %d %d", &u[i], &v[i], &w[i]);
		u[i]--, v[i]--;
		p[i] = i;
	}
	for(i = 0; i < n; i++) S[i] = i, sz[i] = 1;
	sort(p, p + m, [](int i, int j) { return w[i] < w[j]; });
	ll tot = 0;
	for(i = 0; i < m; i++)
		if(find(u[p[i]]) != find(v[p[i]])) {
			join(u[p[i]], v[p[i]]);
			tot += w[p[i]];
			adj[u[p[i]]].pb(pii(v[p[i]], w[p[i]]));
			adj[v[p[i]]].pb(pii(u[p[i]], w[p[i]]));
			got[p[i]] = true;
		}
	dfs(0, 0, INT_MIN, 0);
	for(i = 0; i < m; i++) {
		if(got[i]) { printf("%I64d\n", tot); continue; }
		printf("%I64d\n", tot + ll(w[i])- lca(u[i], v[i]));
	}
}