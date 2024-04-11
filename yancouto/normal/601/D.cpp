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

const int N = 312345;
vector<int> adj[N];
int c[N], sz[N];
char s[N];

int n;

void merge(int u, int v) {
	assert(s[u] == s[v]);
	vector<int> adj2;
	unsigned l = 0, r = 0;
	while(l < adj[u].size() || r < adj[v].size()) {
		if(l < adj[u].size() && r < adj[v].size()) {
			if(s[adj[u][l]] == s[adj[v][r]]) {
				merge(adj[u][l], adj[v][r]);
				adj2.pb(adj[u][l]);
				l++; r++;
			} else if(s[adj[u][l]] < s[adj[v][r]]) {
				adj2.pb(adj[u][l++]);
			} else {
				adj2.pb(adj[v][r++]);
			}
		} else if(l < adj[u].size()) adj2.pb(adj[u][l++]);
		else adj2.pb(adj[v][r++]);
	}
	adj[u] = adj2;
	sz[u] = 1;
	for(int v : adj[u]) sz[u] += sz[v];
}
int best = 0;
int bsz = 0;

void dfs(int u, int p) {
	if(u) adj[u].erase(search_n(adj[u].begin(), adj[u].end(), 1, p));
	for(int v : adj[u]) dfs(v, u);
	sort(adj[u].begin(), adj[u].end(), [](int i, int j) { return s[i] < s[j]; });
	vector<int> adj2;
	for(int i = 0; i < int(adj[u].size()); i++)
		if(i && s[adj[u][i]] == s[adj2.back()])
			merge(adj2.back(), adj[u][i]);
		else
			adj2.pb(adj[u][i]);
	adj[u] = adj2;
	sz[u] = 1;
	for(int v : adj[u]) sz[u] += sz[v];
	if(sz[u] + c[u] > best) {
		best = sz[u] + c[u];
		bsz = 0;
	}
	if(sz[u] + c[u] == best)
		bsz++;
}

int main() {
	int i, j;
	rd(n);
	for(i = 0; i < n; i++) rd(c[i]);
	scanf("%s", s);
	for(i = 0; i < n - 1; i++) {
		int a, b;
		scanf("%d %d", &a, &b); a--; b--;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	dfs(0, 0);
	printf("%d\n%d\n", best, bsz);
}