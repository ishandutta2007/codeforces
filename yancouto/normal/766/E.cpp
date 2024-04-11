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

const int L = 30;
struct no {
	int a[L];
	int sz;
	void join(no &o) {
		for(int i = 0; i < L; i++) a[i] += o.a[i];
		sz += o.sz;
	}
	void swap(no &o) {
		for(int i = 0; i < L; i++) std::swap(a[i], o.a[i]);
		std::swap(sz, o.sz);
	}
};

const int N = 112345;
no s[N];
vector<int> adj[N];
vector<int> el[N];
int a[N], x[N];


ll tot = 0;
void add(int val, no &n) {
	for(int i = 0; i < L; i++)
		if((val >> i) & 1)
			tot += (ll(n.sz - n.a[i]) << ll(i));
		else
			tot += (ll(n.a[i]) << ll(i));
}

void dfs(int u, int p, int cur) {
	tot += ll(a[u]);
	cur ^= a[u];
	x[u] = cur;

	for(int v : adj[u])
		if(v != p) {
			dfs(v, u, cur);
			add((cur ^ a[u]), s[v]);
			if(el[u].size() < el[v].size()) el[u].swap(el[v]), s[u].swap(s[v]);
			for(int x : el[v]) {
				el[u].pb(x);
				add((::x[x] ^ ::a[u]), s[u]);
			}
			el[v].clear();
			s[u].join(s[v]);
		}
	el[u].pb(u);
	for(int i = 0; i < L; i++)
		s[u].a[i] += ((x[u] >> i) & 1);
	s[u].sz++;
}

int n;

int main() {
	int i;
	rd(n);
	for(i = 0; i < n; i++) rd(a[i]);
	for(i = 0; i < n - 1; i++) {
		int u, v;
		rd(u); rd(v); u--; v--;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dfs(0, -1, 0);
	printf("%lld\n", tot);
}