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
const int N = 512345;
int C[N];
vector<int> c[N], s[N], adj[N];
set<int> co[N];

void set_color(int co, int CO) {
	C[co] = CO;
	for(int u : c[co])
		::co[u].erase(CO);
}

void go(int u, int p) {
	for(int c : ::s[u]) {
		if(C[c]) continue;
		assert(!co[u].empty());
		set_color(c, *co[u].begin());
	}
	for(int v : adj[u])
		if(v != p)
			go(v, u);
}

int main() {
	int i, j, m, x;
	int a, b, k;
	rd(n); rd(m);
	int num = 0;
	for(i = 0; i < n; i++) {
		rd(k);
		num = max(num, k);
		for(j = 1; j <= k; j++)
			co[i].insert(j);
		while(k--) {
			rd(x); x--;
			c[x].pb(i);
			s[i].pb(x);
		}
	}
	for(i = 0; i < n - 1; i++) {
		rd(a); rd(b); a--; b--;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	for(i = 0; i < m; i++)
		if(c[i].empty())
			C[i] = 1, num = max(num, 1);
	go(0, -1);
	printf("%d\n", num);
	for(i = 0; i < m; i++)
		printf("%d%c", C[i], " \n"[i == m - 1]);
}