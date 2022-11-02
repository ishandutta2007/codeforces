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
#	define debug(args...) ((void) 0)
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

const int N = 1123456;

int n;

int tempo;
int seen[N], d[N], low[N], cp[N];
int a[N], b[N], w[N];
ll memo[N];
int st[N], sn;
vector<int> adj[N], adj2[N];
int cn;

ll full(ll w) {
	if(w == 0) return 0;
	ll k = (sqrt(1 + 8 * w) - 1) / 2;
	k--;
	while(((k + 1) * (k + 2)) / 2 <= w) k++;

	return w + k * w - (((k + 1) * k * (k + 1)) / 2 - (k * (k + 1) * (2 * k + 1)) / 6);
}

void dfs(int u) {
	seen[u] = 1;
	st[sn++] = u;
	low[u] = d[u] = tempo++;
	for(int e : adj[u])
		if(seen[b[e]])
			low[u] = min(low[u], d[b[e]]);
		else {
			dfs(b[e]);
			low[u] = min(low[u], low[b[e]]);
		}
	if(low[u] == d[u]) {
		int a = -1;
		while(a != u) {
			a = st[--sn];
			low[a] = d[a] = INT_MAX;
			cp[a] = cn;
			for(int e : adj[a]) adj2[cn].pb(e);
		}
		ll own = 0;
		for(int e : adj2[cn])
			if(cp[b[e]] != cn)
				memo[cn] = max(memo[cn], w[e] + memo[cp[b[e]]]);
			else
				own += full(w[e]);
		memo[cn] += own;
		cn++;
	}
}


int main() {
	int i, j;
	int m, s;
	rd(n); rd(m);
	for(i = 0; i < m; i++) {
		rd(a[i]); rd(b[i]); rd(w[i]);
		adj[a[i]].pb(i);
	}
	rd(s);
	for(i = 1; i <= n; i++)
		if(!seen[i])
			dfs(i);
	ll ans = memo[cp[s]];
	printf("%lld\n", ans);
}