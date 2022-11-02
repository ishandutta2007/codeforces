#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef long long ll;
typedef pair<int, ll> pii;
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
multiset<ll> s[N];
vector<pii> adj[N];
int ans[N], a[N];

void solve(int u, int p, ll w) {
	for(pii e : adj[u])
		if(e.fst != p) {
			solve(e.fst, u, w + e.snd);
			if(s[u].size() < s[e.fst].size()) s[u].swap(s[e.fst]);
			for(ll v : s[e.fst]) s[u].insert(v);
		}
	while(!s[u].empty() && *s[u].rbegin() > w) s[u].erase(prev(s[u].end()));
	ans[u] = s[u].size();
	s[u].insert(w - ll(a[u]));
}

int main() {
	int i, j, x, w;
	rd(n);
	for(i = 0; i < n; i++) rd(a[i]);
	for(i = 1; i < n; i++) {
		rd(x); rd(w); x--;
		adj[i].pb(pii(x, w));
		adj[x].pb(pii(i, w));
	}
	solve(0, -1, 0);
	for(i = 0; i < n; i++) printf("%d ", ans[i]);
	putchar('\n');
}