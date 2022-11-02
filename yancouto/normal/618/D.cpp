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
vector<int> adj[N];
int ar[N];
int tot;
int dfs(int u, int p) {
	if(u) adj[u].erase(search_n(adj[u].begin(), adj[u].end(), 1, p));
	for(int v : adj[u])
		dfs(v, u);
	if(u && ar[u] < 2 && ar[p] < 2) ar[u]++, ar[p]++, tot++;
}

int main() {
	int i, n, a, b; ll x, y;
	scanf("%d %I64d %I64d", &n, &x, &y);
	for(i = 0; i < n - 1; i++) {
		scanf("%d %d", &a, &b); a--; b--;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	if(x >= y) {
		for(i = 0; i < n && adj[i].size() != n - 1; i++);
		if(i == n) printf("%I64d\n", ll(n - 1) * y);
		else printf("%I64d\n", ll(n - 2) * y + x);
		return 0;
	}
	dfs(0, 0);
	printf("%I64d\n", ll(tot) * x + ll((n - 1) - tot) * y);
}