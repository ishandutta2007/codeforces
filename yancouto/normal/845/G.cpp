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

const int N = 112345;
int seen[N];

int xo[N];
int all[N], an;
vector<pii> adj[N];

void dfs(int u, int x) {
	xo[u] = x;
	seen[u] = 1;
	for(pii e : adj[u]) {
		if(!seen[e.fst])
			dfs(e.fst, x ^ e.snd);
		else
			all[an++] = x ^ xo[e.fst] ^ e.snd;
	}
}

int main() {
	int i, j;
	int n, m, a, b, c;
	rd(n); rd(m);
	for(i = 0; i < m; i++) {
		rd(a); rd(b); rd(c);
		adj[a].pb(pii(b, c));
		adj[b].pb(pii(a, c));
	}
	dfs(1, 0);
	i = 0;
	for(int b = 27; b >= 0; b--) {
		swap(all[i], *max_element(all + i, all + an));
		if(!((all[i] >> b) & 1)) continue;
		for(int j = i + 1; j < an; j++)
			if((all[j] >> b) & 1)
				all[j] ^= all[i];
		i++;
	}
	int x = xo[n];
	for(i = 0; i < an; i++)
		x = min(x, all[i] ^ x);
	printf("%d\n", x);
}