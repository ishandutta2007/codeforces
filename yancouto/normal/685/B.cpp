#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
#ifdef ONLINE_JUDGE
#	define lld I64d
#	define debug(args...) {}
#else
#	define debug(args...) fprintf(stderr, args)
#endif
const int N = 312345;

int sz[N], ch[N], pos[N];
vector<int> v[N], adj[N];


int dfs0(int u) {
	sz[u] = 1;
	for(int v : adj[u])
		sz[u] += dfs0(v);
	return sz[u];
}


void dfs(int u, int c) {
	ch[u] = c; pos[u] = v[c].size();
	v[c].pb(u);
	if(adj[u].empty()) return;
	int mi = adj[u][0];
	for(int v : adj[u])
		if(sz[mi] < sz[v])
			mi = v;
	dfs(mi, c);
	for(int v : adj[u])
		if(mi != v)
			dfs(v, v);
}



int main() {
	int i, j, n, q, x;
	scanf("%d %d", &n, &q);
	for(i = 1; i < n; i++) {
		scanf("%d", &x);
		adj[x-1].pb(i);
	}
	dfs0(0);
	dfs(0, 0);
	for(i = 0; i < q; i++) {
		scanf("%d", &x); x--;
		if(adj[x].empty()) { printf("%d\n", x + 1); continue; }
		int c = ch[x];
		int l = pos[x] + 1, r = v[c].size() - 1;
		while(l < r) {
			int m = (l + r) / 2;
			if(2 * sz[v[c][m]] <= sz[x]) r = m;
			else l = m + 1;
		}
		printf("%d\n", v[c][l - 1] + 1);
	}
}