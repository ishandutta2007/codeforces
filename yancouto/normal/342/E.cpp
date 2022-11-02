#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
#ifdef ONLINE_JUDGE
#	define debug(args...) {}
#else
#	define debug(args...) fprintf(stderr, args)
#endif

const int N = 112345;
int n;
vector<int> adj[N];
int p[N], sz[N], mrk[N], best[N];

int dfs(int u, int p) {
	//printf("dfs(%d, %d)\n", u, p);
	sz[u] = 1;
	for(int v : adj[u])
		if(v != p && !mrk[v])
			sz[u] += dfs(v, u);
	return sz[u];
}

int d[20][N];

void dfs2(int u, int p, int hc, int h) {
	d[hc][u] = h;
	for(int v : adj[u])
		if(v != p && !mrk[v])
			dfs2(v, u, hc, h + 1);
}

int go(int u, int p, int h) {
	//printf("go(%d, %d, %d)\n", u, p, h);
	dfs(u, u);
	int S = sz[u];
	int lst = u;
	while(true) {
		int mxi = -1;
		for(int v : adj[u])
			if(v != lst && !mrk[v] && (mxi == -1 || sz[v] > sz[mxi]))
				mxi = v;
		//printf("%d->%d(?)\n", u, mxi);
		if(mxi != -1 && sz[mxi] * 2 >= S)
			lst = u, u = mxi;
		else break;
	}
	::p[u] = p;
	//printf("%d->%d\n", p, u);
	mrk[u] = h;
	best[u] = 1e8;
	dfs2(u, u, mrk[u], 0);
	for(int v : adj[u])
		if(!mrk[v])
			go(v, u, h + 1);
}

int _dist(int a, int b) {
	int oa = a, ob = b;
	while(a != b) {
		if(mrk[a] < mrk[b]) swap(a, b);
		a = p[a];
	}
	return d[mrk[a]][oa] + d[mrk[a]][ob];
}

void paint(int u) {
	for(int v = u; v != -1; v = p[v])
		best[v] = min(best[v], d[mrk[v]][u]);
}
int query(int u) {
	int ans = INT_MAX;
	for(int v = u; v != -1; v = p[v])
		ans = min(ans, d[mrk[v]][u] + best[v]);
	return ans;
}

int main() {
	int i, j, q, a, b, op;
	scanf("%d %d", &n, &q);
	for(i = 0; i < n - 1; i++) {
		scanf("%d %d", &a, &b); a--; b--;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	go(0, -1, 1);
	paint(0);
	for(i = 0; i < q; i++) {
		scanf("%d %d", &op, &a); a--;
		if(op == 1) paint(a);
		else printf("%d\n", query(a));
	}
}