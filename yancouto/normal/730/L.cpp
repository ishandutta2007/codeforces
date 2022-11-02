#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
inline ll mod2(ll x) { if(x >= modn) x -= modn; return x; }
#ifdef ONLINE_JUDGE
#	define debug(args...) {}
#else
#	define debug(args...) fprintf(stderr, args)
#endif
#define plus asja

ll fexp(ll x, ll p) {
	ll r = 1;
	for(; p; p >>= 1, x = mod(x * x))
		if(p & 1)
			r = mod(r * x);
	return r;
}

template<class num> inline void read(num &x) {
	char c;
	while(isspace(c = getchar()));
	bool neg = false;
	if(!isdigit(c)) neg = (c == '-'), x = 0;
	else x = c - '0';
	while(isdigit(c = getchar()))
		x = (x << 3) + (x << 1) + c - '0';
	if(neg) x = -x;
}
const int N = 412345;
char s[N];
int no[N], mt[N], en;
ll hs[N], p10[N];
vector<int> adj[N], plus[N], mult[N], ops[N];
vector<ll> sums[N], mults[N];
int st[N], sn;
void pre() {
	int i;
	st[sn++] = 0;
	for(i = 1; s[i]; i++) {
		if(s[i] == '(')
			adj[st[sn - 1]].pb(i), st[sn++] = i;
		if(isdigit(s[i]) && !isdigit(s[i - 1]))
			adj[st[sn - 1]].pb(i);
		if(s[i] == '+') plus[st[sn - 1]].pb(i);
		if(s[i] == '*') mult[st[sn - 1]].pb(i);
		if(s[i] == '+' || s[i] == '*') ops[st[sn - 1]].pb(i);
		no[i] = st[sn - 1];
		if(s[i] == '(' || s[i] == ')') no[i] = st[sn - 2];
		if(s[i] == ')') {
			mt[i] = st[sn - 1];
			mt[st[sn - 1]] = i;
			adj[st[sn - 1]].pb(i + 1);
			sn--;
		}
		hs[i] = mod(10ll * hs[i - 1] + ll(isdigit(s[i])? s[i] - '0' : 0));
	}
	adj[0].pb(i + 1);
	p10[0] = 1;
	for(i = 1; i < N; i++) p10[i] = mod(p10[i - 1] * 10ll);
}

ll vval[N];
inline ll val(int l, int r) {
	assert(l <= r);
	if(s[l] == '(') assert(mt[l] == r);
	if(s[l] == '(') return vval[l];
	return mod(hs[r] - mod(hs[l - 1] * p10[r - l + 1]) + modn);
}

typedef function<ll (ll, ll)> op;
ll sum(ll a, ll b) { return mod2(a + b); }
ll mul(ll a, ll b) { return mod(a * b); }

const int M = 10 * N;
int L[M], R[M];
ll tr[M];

vector<int> cmul[N], zeros[N], invm[N];
ll go(int u) {
	ll cur = 1, val = 0;
	for(int i = 0; i < adj[u].size() - 1; i++) {
		if(i && s[ops[u][i-1]] == '+') sums[u].pb(cur), val = mod2(val + cur), cur = 1;
		ll v;
		if(s[adj[u][i]] == '(') v = go(adj[u][i]);
		else v = ::val(adj[u][i], adj[u][i + 1] - 2);
		cur = mod(cur * v);
		mults[u].pb(v? v : 1ll);
		zeros[u].pb(v == 0);
	}
	ll all = 1;
	for(ll x : mults[u]) all = mod(all * x);
	invm[u].resize(mults[u].size());
	invm[u][mults[u].size() - 1] = fexp(all, modn - 2);
	for(int i = mults[u].size() - 2; i >= 0; i--) invm[u][i] = mod(invm[u][i + 1] * mults[u][i + 1]);
	for(int i = 1; i < mults[u].size(); i++) mults[u][i] = mod(mults[u][i - 1] * mults[u][i]), zeros[u][i] += zeros[u][i - 1];
	int j = 0;
	for(int i = 0; i < mult[u].size(); i++) {
		while(ops[u][j] < mult[u][i]) j++;
		cmul[u].pb(j + 1);
	}
	sums[u].pb(cur); val = mod2(val + cur);
	for(int i = 1; i < sums[u].size(); i++) sums[u][i] = mod2(sums[u][i - 1] + sums[u][i]);
	vval[u] = val;
	return val;
}

inline ll querys(int u, int l, int r) {
	return mod(sums[u][r] - (l? sums[u][l - 1] : 0ll) + modn);
}

inline ll querym(int u, int l, int r) {
	int nz = zeros[u][r] - (l? zeros[u][l - 1] : 0);
	if(nz) return 0;
	return mod(mults[u][r] * (l? invm[u][l - 1] : 1ll));
}

inline int solve(int l, int r) {
	if(no[l] != no[r]) return -1;
	if(s[l] == '+' || s[l] == '*' || s[l] == ')' || s[r] == '+' || s[r] == '*' || s[r] == '(') return -1;
	if(s[l] == '(' && mt[l] > r) return -1;
	if(s[r] == ')' && mt[r] < l) return -1;
	int u = no[l];
	auto sl = lower_bound(plus[u].begin(), plus[u].end(), l);
	auto sr = upper_bound(plus[u].begin(), plus[u].end(), r);
	if(sl == sr) {
		// caso sem somas
		auto ml = lower_bound(mult[u].begin(), mult[u].end(), l);
		auto mr = upper_bound(mult[u].begin(), mult[u].end(), r);
		if(ml == mr) return val(l, r);
		else return mod(mod(val(l, (*ml) - 1) * querym(u, cmul[u][ml - mult[u].begin()], cmul[u][(mr - mult[u].begin()) - 1] - 1)) * val((*prev(mr)) + 1, r));
	} else {
		ll res = querys(u, (sl - plus[u].begin()) + 1, (sr - plus[u].begin()) - 1);
		ll left, right;
		auto ml = lower_bound(mult[u].begin(), mult[u].end(), l);
		auto mr = upper_bound(mult[u].begin(), mult[u].end(), *sl);
		if(ml == mr) left = val(l, (*sl) - 1);
		else left = mod(val(l, (*ml) - 1) * querym(u, cmul[u][ml - mult[u].begin()], cmul[u][(mr - mult[u].begin()) - 1]));
		ml = lower_bound(mult[u].begin(), mult[u].end(), *prev(sr));
		mr = upper_bound(mult[u].begin(), mult[u].end(), r);
		if(ml == mr) right = val((*prev(sr)) + 1, r);
		else {
			right = mod(val((*prev(mr)) + 1, r) * querym(u, cmul[u][ml - mult[u].begin()] - 1, cmul[u][(mr - mult[u].begin()) - 1] - 1));
		}
		return mod2(res + mod2(left + right));
	}
}


int main() {
	int n;
	int i, j, l, r;
	scanf("%s", s + 1);
	pre();
	go(0);
	read(n);
	while(n--) {
		read(l); read(r);
		printf("%d\n", solve(l, r));
	}
}