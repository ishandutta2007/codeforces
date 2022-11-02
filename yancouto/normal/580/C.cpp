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
int m, c[100009];
vector<int> adj[100009];
int dfs(int u, int p, int x) {
	if(x > m) return 0;
	if(u && adj[u].size() == 1) return 1;
	int t = 0;
	for(int v : adj[u])
		if(v != p)
			t += dfs(v, u, (x + c[v]) * c[v]);
	return t;
}

int main() {
	int n, a, b, i;
	scanf("%d %d", &n, &m);
	for(i = 0; i < n; i++)
		scanf("%d", &c[i]);
	for(i = 0; i < n - 1; i++) {
		scanf("%d %d", &a, &b);
		adj[--a].pb(--b);
		adj[b].pb(a);
	}
	printf("%d\n", dfs(0, 0, c[0]));
}