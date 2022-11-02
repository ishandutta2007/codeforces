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

inline int sign(int x) { return (x > 0) - (x < 0); }
const int N = 312345;
vector<int> vec[N];
set<int> adj[N];
int c[N];

void go(int u) {
	if(c[u] == 0) return;
	vector<int> nx;
	for(int v : adj[u])
		if(c[v] == INT_MIN) {
			c[v] = c[u] + sign(c[u]);
			debug("<c[%d] = %d\n", v + 1, c[v]);
			nx.pb(v);
		}
	for(int v : nx)
		go(v);
}


bool valid() {
	debug("=== VALIDITY TEST ===\n");
	int i;
	for(i = 0; i < n; i++)
		if(c[i] == INT_MIN)
			return false;
	for(i = 0; i < n; i++) debug("c[%d] = %d\n", i + 1, c[i]);
	debug("no undef\n");
	for(i = 0; i < n; i++)
		for(int j : adj[i])
			if(abs(c[j] - c[i]) > 1)
				return false;
	int mn = *min_element(c, c + n);
	debug("no wrong connected\n");
	for(i = 0; i < n; i++) vec[c[i] - mn].pb(i);
	for(i = 0; i < N - 1; i++)
		for(int x : vec[i])
			for(int y : vec[i + 1])
				if(!adj[x].count(y))
					return false;
	for(i = 0; i < N; i++)
		for(int x : vec[i])
			for(int y : vec[i])
				if(x != y && !adj[x].count(y))
					return false;
	debug("no wrong disconnected\n");
	return true;
}

pii find_dis(set<int> &S) {
	for(int x : S)
		for(int y : S)
			if(x != y && !adj[x].count(y))
				return pii(x, y);
	return pii(-1, -1);
}

void solve(int i, int o) {
	debug("%d and %d\n", i, o);
	c[i] = 0;
	c[o] = -1;
	for(int x : adj[i])
		if(c[x] == INT_MIN && !adj[o].count(x)) {
			c[x] = 1;
			debug(">c[%d] = %d\n", x+1, 1);
		}
	for(int x : adj[i])
		if(c[x] == 1)
			for(int y : adj[x])
				if(c[y] == INT_MIN && adj[i].count(y)) {
					c[y] = 0;
					debug(">>c[%d] = %d\n", y+1, 0);
				}
	for(int x : adj[i])
		if(c[x] == INT_MIN) {
			c[x] = -1;
			debug(">>>c[%d] = %d\n", x+1, -1);
		}
	for(int x : adj[i])
		go(x);
	if(valid()) {
		puts("YES");
		int mn = *min_element(c, c + n);
		for(i = 0; i < n; i++) printf("%d ", c[i] - mn + 1);
		putchar('\n');
	} else puts("NO");

}

int A[N], B[N];
ll val[N], val2[N];

int main() {
	int i, j, m, a, b;
	rd(n); rd(m);
	for(i = 0; i < m; i++) {
		rd(a); rd(b); a--; b--;
		adj[a].insert(b);
		adj[b].insert(a);
		A[i] = a; B[i] = b;
	}
	for(i = 0; i < n; i++) c[i] = INT_MIN, adj[i].insert(i);
	for(i = 0; i < n; i++) {
		for(int x : adj[i]) val[i] = 123456789ll * val[i] + x;
		for(int x : adj[i]) val2[i] = mod(1123456ll * val2[i] + x);
	}
	for(i = 0; i < m; i++) {
		if(val[A[i]] == val[B[i]] && val2[A[i]] == val2[B[i]]) continue;
		for(int x : adj[A[i]])
			if(!adj[B[i]].count(x)) {
				solve(A[i], B[i]);
				return 0;
			}
		solve(B[i], A[i]);
		return 0;
	}
	puts("YES");
	for(i = 0; i < n; i++) printf("1 ");
	putchar('\n');
}