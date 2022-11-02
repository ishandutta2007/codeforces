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

template<class num> inline void rd(num &x) {
	char c;
	while(isspace(c = getchar()));
	bool neg = false;
	if(!isdigit(c)) neg = (c == '-'), x = 0;
	else x = c - '0';
	while(isdigit(c = getchar()))
		x = (x << 3) + (x << 1) + c - '0';
	if(neg) x = -x;
}

int n, m;

const int N = 1123456;
int seen[N], a[N], b[N], lp[N];
vector<int> adj[N];

void dfs(int u) {
	if(seen[u]) return;
	seen[u] = true;
	for(int v : adj[u])
		dfs(v);
}

int main() {
	int i;
	rd(n); rd(m);
	ll L = 0;
	for(i = 0; i < m; i++) {
		rd(a[i]); rd(b[i]); a[i]--; b[i]--;
		if(a[i] == b[i]) { lp[a[i]]++, L++; continue; }
		adj[a[i]].pb(b[i]);
		adj[b[i]].pb(a[i]);
	}
	ll tot = L * ll(m - 1); // starting in all loops
	dfs(a[0]);
	for(i = 0; i < n; i++)
		if((!adj[i].empty() || lp[i]) && !seen[i]) {
			puts("0"); // isolated
			return 0;
		}
	for(i = 0; i < m; i++) {
		if(a[i] == b[i]) continue;
		tot += ll(adj[a[i]].size()) + ll(adj[b[i]].size()) + L - 2;
	}
	printf("%lld\n", tot / 2);
}