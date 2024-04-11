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
ll ans;
const int N = 212345;
vector<int> adj[N];
ll V[N];

struct st {
	ll qtp;
	ll qtn;
	ll sump;
	ll sumn;

	void init(ll v) {
		qtp = 1;
		qtn = 0;
		sump = v;
		sumn = 0;
		ans += v;
	}
	void join(ll v, st &o) {
		ans = mod(ans + qtp * (-o.sump - o.sumn) + (o.qtp + o.qtn) * sump);
		ans = mod(ans + qtn * (o.sump + o.sumn) + (o.qtp + o.qtn) * (-sumn));
		ans = mod(ans + o.qtp * (-sump - sumn) + (qtp + qtn) * o.sump);
		ans = mod(ans + o.qtn * (sump + sumn) + (qtp + qtn) * (-o.sumn));
		ans = mod(ans + modn);
		qtp += o.qtn;
		qtn += o.qtp;
		sump = mod(sump + (-o.sumn) + o.qtn * v);
		sump = mod(sump + modn);
		sumn = mod(sumn + (-o.sump) + o.qtp * v);
		sumn = mod(sumn + modn);
	}
} s[N];


void solve(int u, int p) {
	s[u].init(V[u]);
	for(int v : adj[u]) {
		if(v == p) continue;
		solve(v, u);
		s[u].join(V[u], s[v]);
	}
}

int main() {
	int i;
	rd(n);
	for(i = 0; i < n; i++) rd(V[i]);
	for(i = 0; i < n - 1; i++) {
		int a, b;
		rd(a); rd(b); a--; b--;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	solve(0, 0);
	printf("%lld\n", ans);
}