#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ull modn = 1000000007;
inline ull mod(ull x) { return x % modn; }

const int MAX = 100009;
int out[MAX], deg[MAX], c[MAX];
vector<int> ad1[MAX], adj[MAX];
ll memo[MAX][2], memo2[MAX][2];
ll dv(int, int, bool);
ll solve(int u, int has_black) {
	//printf("solve(%d, %d)\n", u, has_black);
	ll &r = memo[u][has_black];
	if(r != -1) return r;
	if(adj[u].empty()) return r = 1;
	r = 0;
	bool orange = (c[u] == 1);
	if(has_black) {
		ll a1 = 0;
		if(!orange)
			a1 = dv(u, adj[u].size(), false);
		r = mod(r + a1);
		a1 = dv(u, adj[u].size(), true);
		r = mod(r + a1);
	} else {
		ll a1 = dv(u, adj[u].size(), orange);
		r = mod(r + a1);
	}
	//printf("(%d, %d) = %I64d\n", u, has_black, r);
	return r;
}

ll dv(int u, int m, bool has_black) {
	//printf("dv(%d, %d, %d)\n", u, m, has_black);
	ll &r = memo2[adj[u][m - 1]][has_black];
	if(r != -1) return r;
	if(m == 1) return r = solve(adj[u][0], has_black);
	r = mod(dv(u, m - 1, has_black) * solve(adj[u][m-1], true));
	if(!has_black) r = mod(r + dv(u, m - 1, true) * solve(adj[u][m-1], false));
	//printf("(%d, %d, %d) = %I64d\n", u, m, has_black, r);
	return r;
}

void dfs(int u, int p) {
	for(int v : ad1[u])
		if(!out[v] && v != p) {
			adj[u].pb(v);
			dfs(v, u);
		}
}

int main() {
	int i, n, x;
	scanf("%d", &n);
	for(i = 0; i < n - 1; i++) {
		scanf("%d", &x);
		ad1[i + 1].pb(x);
		ad1[x].pb(i + 1);
		deg[i + 1]++; deg[x]++;
	}
	for(i = 0; i < n; i++)
		scanf("%d", &c[i]);
	int st[MAX], sn;
	for(i = 0; i < n; i++)
		if(deg[i] == 1 && c[i] == 0)
			st[sn++] = i;
	while(sn) {
		x = st[--sn];
		out[x] = 1;
		for(int v : ad1[x])
			if(--deg[v] == 1 && c[v] == 0)
				st[sn++] = v;
	}
	for(i = 0; c[i] == 0 || deg[i] > 1; i++);
	if(deg[i] == 0) { puts("1"); return 0; }
	dfs(i, -1);
	memset(memo, -1, sizeof memo);
	memset(memo2, -1, sizeof memo2);
	printf("%I64d\n", solve(adj[i][0], true));
}