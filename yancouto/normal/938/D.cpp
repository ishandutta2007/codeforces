#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef long long ll;
typedef pair<ll, ll> pii;
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

int n, m;
const int N = 212345;
vector<pii> adj[N];
ll d[N];

int main() {
	int i, j;
	rd(n); rd(m);
	for(i = 0; i < m; i++) {
		int a, b; ll c;
		rd(a); rd(b); rd(c);
		adj[a].pb(pii(b, 2ll * c));
		adj[b].pb(pii(a, 2ll * c));
	}
	for(i = 0; i < n; i++) {
		ll c;
		rd(c);
		adj[0].pb(pii(i + 1, c));
	}
	priority_queue<pii> pq;
	pq.push(pii(0, 0));
	memset(d, -1, sizeof d);
	while(!pq.empty()) {
		pii x = pq.top(); pq.pop();
		int u = x.snd;
		if(d[u] != -1) continue;
		d[u] = -x.fst;
		for(pii e : adj[u])
			pq.push(pii(-d[u] - e.snd, e.fst));
	}
	for(i = 1; i <= n; i++) printf("%lld ", d[i]);
	putchar('\n');
}