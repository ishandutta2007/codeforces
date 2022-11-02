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

int n;

const int N = 212345;
bool seen[N];
set<int> cx, cy;
bool cyc;
int x[N], y[N];
vector<int> adj[N];

void go(int u, int p) {
	if(seen[u]) {
		cyc = true;
		return;
	}
	seen[u] = true;
	cx.insert(x[u]);
	cy.insert(y[u]);
	for(int v : adj[u])
		if(v != p)
			go(v, u);
}

map<int, map<int, int>> sx, sy;

int main() {
	int i, j;
	rd(n);
	for(i = 0; i < n; i++) {
		rd(x[i]); rd(y[i]);
		sx[x[i]][y[i]] = i;
		sy[y[i]][x[i]] = i;
	}
	for(i = 0; i < n; i++) {
		auto it = sx[x[i]].find(y[i]);
		if(next(it) != sx[x[i]].end()) adj[i].pb(next(it)->snd);
		if(it != sx[x[i]].begin()) adj[i].pb(prev(it)->snd);
		it = sy[y[i]].find(x[i]);
		if(next(it) != sy[y[i]].end()) adj[i].pb(next(it)->snd);
		if(it != sy[y[i]].begin()) adj[i].pb(prev(it)->snd);
	}
	ll ans = 1;
	for(i = 0; i < n; i++) {
		if(seen[i]) continue;
		cx.clear(); cy.clear();
		cyc = false;
		go(i, -1);
		ll t = ll(cx.size()) + ll(cy.size());
		ll p2 = 1;
		while(t--) p2 = mod(p2 * 2ll);
		ans = mod(ans * mod(p2 - ll(!cyc) + modn));
	}
	printf("%d\n", int(ans));
}