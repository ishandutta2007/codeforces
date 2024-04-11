#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<ll, ll> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

struct no {
	int i; ll l, m, w;
	char ch;
	no() {}
	no(int i_, ll a, ll b, ll c, char d=0) : i(i_), l(a), m(b), w(c), ch(d) {}
	bool operator < (no o) const {
		if(l != o.l) return l < o.l;
		if(m != o.m) return m < o.m;
		if(w != o.w) return w < o.w;
		if(ch != o.ch) return ch < o.ch;
		return i < o.i;
	}
	bool operator == (no o) const {
		return l == o.l && m == o.m && w == o.w && ch == o.ch && i == o.i;
	}
};
namespace std {
template <>
struct hash<no> {
	std::size_t operator()(const no &o) const {
		return o.i ^ (1 + o.l) ^ (4 + o.m) ^ (7 + o.w) ^ o.ch;
	}
};
template <>
struct hash<pii> {
	std::size_t operator()(const pii &o) const {
		return o.fst ^ o.snd;
	}
};
}
const int N = 30;
int lt[N], mt[N], wt[N];
int n;

unordered_map<pii, ll> best;
unordered_map<pii, no> best_no;
unordered_map<no, no> pai;
void gen1(int i, ll l, ll m, ll w, no p, char lst) {
	no nn(i, l, m, w, lst);
	pai[nn] = p;
	if(i == n / 2) {
		pii x(l - m, l - w);
		if(!best.count(x) || best[x] < l)
			best[x] = l, best_no[x] = nn;
		return;
	}
	gen1(i + 1, l, m + mt[i], w + wt[i], nn, 'L');
	gen1(i + 1, l + lt[i], m, w + wt[i], nn, 'M');
	gen1(i + 1, l + lt[i], m + mt[i], w, nn, 'W');
}

ll mx;
string str;
no x;
char st[200];
void gen2(int i, ll l, ll m, ll w) {
	if(i == n) {
		pii p(m - l, w - l);
		if(!best.count(p) || best[p] + l < mx) return;
		mx = best[p] + l;
		str = st;
		x = best_no[p];
		return;
	}
	st[i - n/2] = 'L';
	gen2(i + 1, l, m + mt[i], w + wt[i]);
	st[i - n/2] = 'M';
	gen2(i + 1, l + lt[i], m, w + wt[i]);
	st[i - n/2] = 'W';
	gen2(i + 1, l + lt[i], m + mt[i], w);
}

void out(char c) {
	if(c == 'L') puts("MW");
	if(c == 'M') puts("LW");
	if(c == 'W') puts("ML");
}

int main() {
	int i;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d %d %d", &lt[i], &mt[i], &wt[i]);
	gen1(0, 0, 0, 0, no(-1, 0, 0, 0), 0);
	mx = LLONG_MIN;
	gen2(n/2, 0, 0, 0);
	if(mx == LLONG_MIN) { puts("Impossible"); return 0; }
	int sn = 0;
	while(x.i > 0) {
		st[sn++] = x.ch;
		x = pai[x];
	}
	while(sn) {
		out(st[--sn]);
		assert(st[sn]);
	}
	for(char c : str)
		out(c);
}