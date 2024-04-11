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

int n;
const int N = 212345;
int seen[N];
vector<int> adj[N];
vector<int> path;
vector<int> ps[N];

void dfs(int u) {
	path.pb(u);
	seen[u] = 1;
	for(int v : adj[u]) {
		if(seen[v]) continue;
		dfs(v);
		path.pb(u);
	}
}

int main() {
	int i, m, k, a, b;
	rd(n); rd(m); rd(k);
	for(i = 0; i < m; i++) {
		rd(a); rd(b); a--; b--;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	dfs(0);
	int mx = (2 * n + k - 1) / k;
	i = 0;
	for(int x : path) {
		ps[i / mx].pb(x + 1);
		i++;
	}
	for(i = 0; i < k; i++) {
		if(ps[i].empty())
			ps[i].pb(1);
		printf("%d", (int) ps[i].size());
		for(int x : ps[i])
			printf(" %d", x);
		putchar('\n');
	}
}