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

inline int T(int v) { return (v << 1); }
inline int F(int v) { return T(v) + 1; }

int n;
const int N = 512345;
vector<int> adj[N];

inline void add_or(int u, int v) {
	adj[u ^ 1].pb(v);
	adj[v ^ 1].pb(u);
}

int st[N], sn, seen[N], tempo;
int d[N], low[N], r[N];
int mrk[N], cn = 1;

void dfs(int u) {
	seen[u] = true;
	d[u] = low[u] = tempo++;
	st[sn++] = u;
	for(int v : adj[u])
		if(seen[v])
			low[u] = min(low[u], d[v]);
		else {
			dfs(v);
			low[u] = min(low[u], low[v]);
		}
	if(low[u] == d[u]) {
		int x;
		do {
			x = st[--sn];
			mrk[x] = cn;
			if(mrk[x ^ 1] == cn) { puts("NO"); exit(0); }
			low[x] = d[x] = INT_MAX;
		} while(x != u);
		cn++;
	}
}

vector<int> v[N];

int main() {
	int i, m, k, x;
	rd(n); rd(m);
	for(i = 0; i < n; i++) rd(r[i]);
	for(i = 0; i < m; i++) {
		rd(k);
		while(k--) {
			rd(x);
			v[--x].pb(i);
		}
	}
	for(i = 0; i < n; i++) {
		assert(v[i].size() == 2);
		int a = v[i].front(), b = v[i].back();
		if(r[i] == 0) {
			add_or(T(a), T(b));
			add_or(F(a), F(b));
		} else {
			add_or(T(a), F(b));
			add_or(F(a), T(b));
		}
	}
	for(i = 0; i < N; i++)
		if(!seen[i])
			dfs(i);
	puts("YES");
}