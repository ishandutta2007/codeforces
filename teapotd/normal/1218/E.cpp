#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Vi = vector<int>;
using Pii = pair<int,int>;
#define pb push_back
#define x first
#define y second
#define rep(i,b,e) for(int i=(b); i<(e); i++)
#define each(a,x) for(auto& a : (x))
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())

#define tem template<class t,class u,class...w>
#define pri(x,y)tem auto operator<<(t& o, u a)->decltype(x,o) { o << y; return o; }
pri(a.print(),"{";a.print();o<<"}");
pri(a.y,"("<<a.x<<", "<<a.y<<")");
pri(all(a),"[";auto d="";for(auto i : a)(o << d << i, d=", "); o << "]");
void DD(...){}
tem void DD(t s, u a, w... k) {
	int b = 44;
	while (*s && *s != b) {
		b += (*s == 40 ? 50 : *s == 41 ? -50 : 0);
		cerr << *s++;
	}
	cerr << ": " << a << *s++; DD(s, k...);
}
tem vector<t> span(const t* a, u n) { return {a, a+n}; }
#ifdef LOC
#define deb(...) (DD("#, "#__VA_ARGS__, __LINE__, __VA_ARGS__), cerr << endl)
#else
#define deb(...)
#endif
#define DBP(...) void print() { DD(#__VA_ARGS__, __VA_ARGS__); }

constexpr ll MOD = 998244353;
constexpr ll ROOT = 31; // order = 1<<23

Vi tmp;

ll modInv(ll a, ll m) {
	if (a == 1) return 1;
	return ((a - modInv(m%a, a))*m + 1) / a;
}

template<int dir> // 1 for DFT, -1 for inverse
void fft(vector<ll>& buf) {
	assert(__builtin_popcount(sz(buf)) == 1);
	int n = sz(buf), bits = 31-__builtin_clz(n);
	int i = (dir > 0 ? 0 : bits-1);

	vector<ll> bases = {1};
	ll c = ROOT;
	rep(k, bits, 23) c = c*c % MOD;
	rep(k, 0, n) bases.pb(bases.back()*c % MOD);

	for (; i >= 0 && i < bits; i += dir) {
		int shift = 1 << (bits-i-1);
		rep(j, 0, 1 << i) rep(k, 0, shift) {
			int a = (j << (bits-i)) | k, b = a|shift;
			auto v1 = buf[a], v2 = buf[b];
			auto base = bases[(dir*(k<<i)) & (n-1)];
			if (dir > 0) {
				buf[b] = (v1-v2)*base % MOD;
			} else {
				v2 *= base;
				buf[b] = (v1-v2) % MOD;
			}
			buf[a] = (v1+v2) % MOD;
		}
	}

	if (dir < 0) {
		ll y = modInv(n, MOD);
		each(x, buf) x = x*y % MOD;
	}
	each(x, buf) if (x < 0) x += MOD;
}

void convolve(vector<ll>& a, vector<ll> b) {
	int len = sz(a) + sz(b) - 1;
	int n = 1 << (32 - __builtin_clz(len));
	a.resize(n); b.resize(n);
	fft<1>(a); fft<1>(b);
	rep(i, 0, n) a[i] = a[i]*b[i] % MOD;
	fft<-1>(a);
	a.resize(len);
}

vector<ll> solve(int b, int e) {
	if (b >= e) return {1};
	if (b+1 == e) return {1, tmp[b]%MOD};
	int m = (b+e) / 2;
	auto vec1 = solve(b, m);
	auto vec2 = solve(m, e);
	convolve(vec1, vec2);
	return vec1;
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(18);

	int n, k; cin >> n >> k;
	Vi elems(n);
	each(e, elems) cin >> e;

	int queries; cin >> queries;
	tmp.resize(n);

	while (queries--) {
		int t; cin >> t;

		if (t == 1) {
			int q, i, d; cin >> q >> i >> d;
			rep(j, 0, n) {
				tmp[j] = q - (i == j+1 ? d : elems[j]);
			}
		} else {
			int q, l, r, d; cin >> q >> l >> r >> d;
			rep(j, 0, n) {
				tmp[j] = q - elems[j] - (j+1 >= l && j+1 <= r ? d : 0);
			}
		}

		auto poly = solve(0, n);
		ll ans = poly[k];
		if (ans < 0) ans += MOD;
		cout << ans << '\n';
	}
}