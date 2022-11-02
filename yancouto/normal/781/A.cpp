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
int c[N];
vector<int> adj[N];

void dfs(int u, int p) {
	int cn = 1;
	for(int v : adj[u]) {
		if(v == p) continue;
		while(cn == c[u] || cn == c[p]) cn++;
		c[v] = cn++;
	}
	for(int v : adj[u])
		if(v != p)
			dfs(v, u);
}

int main() {
	int i, j, a, b;
	rd(n);
	for(i = 0; i < n - 1; i++) {
		rd(a); rd(b); a--; b--;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	for(i = 0; i < n; i++)
		if(adj[i].size() == 1) {
			c[i] = 1;
			c[adj[i].back()] = 2;
			dfs(adj[i].back(), i);
			break;
		}
	printf("%d\n", *max_element(c, c + n));
	for(i = 0; i < n; i++)
		printf("%d ", c[i]);
	putchar('\n');
}