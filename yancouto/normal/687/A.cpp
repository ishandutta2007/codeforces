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

vector<int> adj[N];
int seen[N], c[N];
bool dfs(int u, int C) {
	if(seen[u]) return c[u] != C;
	seen[u] = true;
	c[u] = C;
	for(int v : adj[u])
		if(dfs(v, !C))
			return true;
	return false;
}

int main() {
	int i, j, n, m, a, b;
	scanf("%d %d", &n, &m);
	for(i = 0; i < m; i++) {
		scanf("%d %d", &a, &b); a--; b--;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	for(i = 0; i < n; i++)
		if(!seen[i] && dfs(i, 0)) {
			puts("-1");
			return 0;
		}
	vector<int> v[2];
	for(i = 0; i < n; i++)
		v[c[i]].pb(i + 1);
	for(j = 0; j < 2; j++) {
		printf("%d\n", (int) v[j].size());
		for(int x : v[j]) printf("%d ", x);
		putchar('\n');
	}
}