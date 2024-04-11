#include <bits/stdc++.h>
using namespace std;
#define v first
#define d second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
const int N = 312345;
int seen[N], d[N], low[N], ok[N], p[N], tempo;
vector<pii> adj[N];

void dfs(int u, int p, bool di) {
	::p[u] = p;
	seen[u] = true;
	d[u] = low[u] = tempo++;
	ok[u] = di;
	bool dad = false;
	for(pii e : adj[u])
		if(!seen[e.v]) {
			dfs(e.v, u, di || e.d);
			if(low[e.v] <= d[u] && ok[e.v]) ok[u] = 1;
			low[u] = min(low[u], low[e.v]);
		} else if(dad || e.v != p) {
			low[u] = min(low[u], d[e.v]);
			if(d[e.v] < d[u] && e.d) ok[u] = 1;
		}
		else dad = true;
}

int main() {
	int n, m, a, b, c, i;
	scanf("%d %d", &n, &m);
	for(i = 0; i < m; i++) {
		scanf("%d %d %d", &a, &b, &c); a--; b--;
		adj[a].pb(pii(b, c));
		adj[b].pb(pii(a, c));
	}
	scanf("%d %d", &a, &b); a--; b--; 
	dfs(a, a, 0);
	bool any = ok[b];
	while(p[b] != b) {
		b = p[b];
		any |= ok[b];
	}
	if(any) puts("YES");
	else puts("NO");
}