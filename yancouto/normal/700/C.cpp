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
const int N = 112345;
vector<int> adj[N], ot[N], sons[N];
int seen[N], d[N], low[N], tempo, tt, p[N], c[N], ig;
int a[N], b[N], w[N];


void dfs(int u, int pe) {
	d[u] = tt++;
	seen[u] = 1;
	for(int e : adj[u])
		if((e|1) == (pe|1)) continue;
		else if(!seen[b[e]]) dfs(b[e], e^1), sons[u].pb(e), c[e] = c[e^1] = 1;
		else ot[u].pb(e);
	sort(ot[u].begin(), ot[u].end(), [](int e1, int e2) { return d[b[e1]] < d[b[e2]]; });
}

void dfs2(int u, int pe) {
	p[u] = pe;
	low[u] = d[u] = tt++;
	seen[u] = tempo;
	for(int e : adj[u])
		if((e | 1) == ig) continue;
		else if((e|1) == (pe|1)) continue;
		else if(seen[b[e]] != tempo) {
			dfs2(b[e], e^1);
			low[u] = min(low[u], low[b[e]]);
		} else {
			low[u] = min(low[u], d[b[e]]);
		}
}

int ponte(int s, int t) {
	tempo++;
	dfs2(s, -1);
	if(seen[t] != tempo) return -1;
	int ans = INT_MAX, e = -2;
	for(int u = t; u != s; u = b[p[u]]) {
		if(low[u] > d[b[p[u]]] && w[p[u]] < ans) {
			ans = w[p[u]];
			e = p[u];
		}
	}
	return e;
}

void dfs3(int u, int pe) {
	d[u] = low[u] = tt++;
	p[u] = pe;
	for(int e : sons[u]) {
		dfs3(b[e], e^1);
		low[u] = min(low[u], low[b[e]]);
	}
	int e = -1;
	if(!ot[u].empty() && (ot[u].front()|1) == ig) e = (ot[u].size() > 1? ot[u][1] : -1);
	else if(!ot[u].empty()) e = ot[u][0];
	if(e != -1) low[u] = min(low[u], d[b[e]]);
}

int ponte2(int s, int t) {
	dfs3(s, -1);
	int ans = INT_MAX, e = -2;
	for(int u = t; u != s; u = b[p[u]]) {
		if(low[u] > d[b[p[u]]] && w[p[u]] < ans) {
			ans = w[p[u]];
			e = p[u];
		}
	}
	return e;
}


int main() {
	int i, j, n, m, s, t;
	scanf("%d %d", &n, &m);
	scanf("%d %d", &s, &t); s--; t--;
	for(i = 0; i < 2*m; i += 2) {
		scanf("%d %d %d", &a[i], &b[i], &w[i]); a[i]--; b[i]--;
		a[i+1] = b[i]; b[i+1] = a[i]; w[i+1] = w[i];
		adj[a[i]].pb(i);
		adj[b[i]].pb(i+1);
	}
	dfs(s, -1); tempo = 2000;
	if(!seen[t]) {
		puts("0\n0");
		return 0;
	}
	int ans = INT_MAX;
	int m1 = -1, m2 = -1;
	for(i = 0; i < 2*m; i += 2) {
		ig = i + 1;
		tempo++;
		if(c[i] || c[i+1]) {
			int x = ponte(s, t);
			if(x == -1) {
				if(ans > w[i]) {
					ans = w[i];
					m1 = i;
					m2 = -1;
				}
			} else if(x != -2) {
				if(ans > w[i] + w[x]) {
					ans = w[i] + w[x];
					m1 = i;
					m2 = x;
				}
			}
		} else {
			int x = ponte2(s, t);
			if(x != -2 && ans > w[i] + w[x]) {
				ans = w[i] + w[x];
				m1 = i;
				m2 = x;
			}
		}
	}
	if(ans == INT_MAX) { puts("-1"); return 0; }
	printf("%d\n%d\n", ans, 1 + (m2 != -1));
	printf("%d", (m1 / 2) + 1);
	if(m2 != -1) printf(" %d", (m2 / 2) + 1);
	putchar('\n');
}