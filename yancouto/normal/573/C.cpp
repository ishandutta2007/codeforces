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
int deg[MAX], ok[MAX];
vector<int> adj[MAX];
void dfs(int u, int p) {
	if(deg[u] > 3) return;
	ok[u]++;
	if(deg[u] == 3) return;
	for(int v : adj[u])
		if(v != p)
			dfs(v, u);
}

int main() {
	int i, n, a, b;
	scanf("%d", &n);
	for(i = 0; i < n - 1; i++) {
		scanf("%d %d", &a, &b);
		adj[--a].pb(--b);
		adj[b].pb(a);
		deg[a]++; deg[b]++;
	}
	for(i = 0; i < n; i++)
		if(deg[i] == 1)
			dfs(i, -1);
	for(i = 0; i < n; i++)
		if(deg[i] == 3 && ok[i] <= 1)
			ok[i] = 0;
	for(i = 0; i < n; i++) {
		if(ok[i]) continue;
		int ct = 0;
		for(int v : adj[i])
			if(!ok[v])
				ct++;
		if(ct > 2) break;
	}
	if(i < n) puts("No");
	else puts("Yes");
}