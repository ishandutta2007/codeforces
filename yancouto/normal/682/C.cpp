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
int a[N], c[N], p[N];
vector<int> adj[N];

int tot = 0;
int dfs(int u, ll cur, bool count) {
	if(cur < 0) cur = 0;
	if(count || cur > a[u]) tot++, count = true;
	for(int v : adj[u])
		dfs(v, cur + c[v], count);
	return tot;
}


int main() {
	int i, j, n;
	scanf("%d", &n);
	for(i = 0; i < n; i++) scanf("%d", &a[i]);
	for(i = 1; i < n; i++) {
		scanf("%d %d", &p[i], &c[i]);
		adj[--p[i]].pb(i);
	}
	printf("%d\n", dfs(0, 0, false));
}