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

int p[N], sz[N];
vector<int> adj[N];
double ans[N];
void dfs(int u, double t) {
	ans[u] = t; t = t + 1;
	int sons = sz[u] - 1;
	for(int v : adj[u])
		dfs(v, (sons - sz[v]) / 2. + t);
}

int main() {
	int i, j, n;
	scanf("%d", &n);
	for(i = 1; i < n; i++) {
		scanf("%d", &p[i]);
		adj[--p[i]].pb(i);
	}
	for(i = n - 1; i >= 0; i--) {
		sz[i]++;
		if(i) sz[p[i]] += sz[i];
	}
	dfs(0, 1);
	for(i = 0; i < n; i++) printf("%.10f ", ans[i]);
	putchar('\n');
}