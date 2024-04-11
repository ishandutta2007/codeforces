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

int l[N], r[N];

struct cmp {
	bool operator()(int i, int j) { if(r[i] != r[j]) return r[i] > r[j]; else return i < j; }
};

set<int, cmp> tr[N << 2];

vector<int> tmp;

void get(int i, int l, int r, int mxl, int mnr) {
	if(l > mxl) return;
	if(r <= mxl) {
		for(int j : tr[i])
			if(::r[j] >= mnr)
				tmp.pb(j);
			else
				break;
		return;
	}
	int m = (l + r) / 2;
	get(2 * i, l, m, mxl, mnr);
	get(2 * i + 1, m + 1, r, mxl, mnr);
}

void add(int i, int l, int r, int pi, bool ad) {
	if(ad) tr[i].insert(pi);
	else tr[i].erase(pi);
	if(l == r) return;
	int m = (l + r) / 2;
	if(::l[pi] <= m) add(2 * i, l, m, pi, ad);
	else add(2 * i + 1, m + 1, r, pi, ad);
}

int S[N];

int find(int i) {
	if(S[S[i]] != S[i]) S[i] = find(S[i]);
	//debug("S[%d] = %d\n", i, S[i]);
	return S[i];
}

void join(int a, int b) {
	debug("join(%d, %d)\n", a, b);
	if((a = find(a)) == (b = find(b))) return;
	debug("actual_join(%d, %d)\n", a, b);
	if(a < b) swap(a, b);
	S[b] = a;
}

int ur[N];
struct cmp2 {
	bool operator()(int i, int j) { if(ur[i] != ur[j]) return ur[i] < ur[j]; else return i < j; }
};

int d[N], f[N], tempo;

vector<int> adj[N];
int c[N], cn;

void dfs(int u) {
	d[u] = tempo++;
	for(int v : adj[u])
		dfs(v);
	f[u] = tempo++;
	debug("%d: from %d to %d\n", u, d[u], f[u]);
}

inline bool pai(int u, int p) {
	debug("pai(%d, %d)\n", u, p);
	return d[u] >= d[p] && f[u] <= f[p];
}
int op[N], ul[N];
int mp[N], mn;

int main() {
	int i, j;
	rd(n);
	for(i = 0; i < n; i++) {
		rd(op[i]); rd(l[i]); rd(r[i]); l[i]--; r[i]--;
		if(op[i] == 1) {
			mp[mn++] = i;
			c[cn++] = l[i] + modn; c[cn++] = r[i] + modn;
			S[i] = i;
		}
	}
	sort(c, c + cn);
	cn = unique(c, c + cn) - c;
	set<int, cmp2> mx;
	for(i = 0; i < n; i++) {
		if(op[i] == 2) continue;
		ul[i] = l[i] = lower_bound(c, c + cn, l[i] + modn) - c;
		ur[i] = r[i] = lower_bound(c, c + cn, r[i] + modn) - c;
		debug("[%d] adding (%d, %d)\n", i, l[i], r[i]);
		ur[n] = l[i];
		for(auto it = mx.upper_bound(n); it != mx.end() && ul[*it] < r[i];) {
			adj[i].pb(*it);
			debug("%d -> %d\n", i, *it);
			ul[i] = min(ul[i], ul[*it]);
			ur[i] = max(ur[i], ur[*it]);
			it = mx.erase(it);
		}
		mx.insert(i);
	}
	for(int x : mx)
		dfs(x);
	mx.clear();
	for(i = 0; i < n; i++) {
		if(op[i] == 1) {
			tmp.clear();
			get(1, 0, cn - 1, l[i] - 1, l[i] + 1);
			for(int x : tmp) add(1, 0, cn - 1, x, false), join(i, x);
			tmp.clear();
			get(1, 0, cn - 1, r[i] - 1, r[i] + 1);
			for(int x : tmp) add(1, 0, cn - 1, x, false), join(i, x);
			l[i] = ul[i]; r[i] = ur[i];
			add(1, 0, cn - 1, i, true);
		} else {
			debug(">>>>QUERY(%d, %d)\n", mp[l[i]], mp[r[i]]);
			if(pai(find(mp[l[i]]), find(mp[r[i]]))) puts("YES");
			else puts("NO");
		}
	}
}