#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<list>
#include<set>
#include<string>
#include<iomanip>
#include<math.h>
#include<bitset>
#include<functional>
using namespace std;
typedef long long ll;
#define lscan(x) scanf("%I64d",&x);
#define lprint(x) printf("%I64d",x);
ll gcd(ll a, ll b) {
	int c = a % b;
	while (c != 0) {
		a = b;
		b = c;
		c = a % b;
	}
	return b;
}
long long extGCD(long long a, long long b, long long &x, long long &y) {
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	long long d = extGCD(b, a%b, y, x);
	y -= a / b * x;
	return d;
}
struct UnionFind {
	vector<int> par;

	UnionFind(int N) : par(N) {
		for (int i = 0; i < N; i++) par[i] = i;
	}

	int root(int x) {
		if (par[x] == x) return x;
		return par[x] = root(par[x]);
	}

	void unite(int x, int y) {
		int rx = root(x);
		int ry = root(y);
		if (rx == ry) return;
		par[rx] = ry;
	}

	bool same(int x, int y) {
		int rx = root(x);
		int ry = root(y);
		return rx == ry;
	}
};

ll M = 1000000007;

vector<ll> fac(1000001); //n!(mod M)
vector<ll> ifac(1000001); //k!^{M-2} (mod M)

ll mpow(ll x, ll n) {
	ll ans = 1;
	while (n != 0) {
		if (n & 1) ans = ans * x % M;
		x = x * x % M;
		n = n >> 1;
	}
	return ans;
}
ll mpow2(ll x, ll n, ll mod) {
	ll ans = 1;
	while (n != 0) {
		if (n & 1) ans = ans * x % mod;
		x = x * x % mod;
		n = n >> 1;
	}
	return ans;
}
void setcomb() {
	fac[0] = 1;
	ifac[0] = 1;
	for (ll i = 0; i < 1000000; i++) {
		fac[i + 1] = fac[i] * (i + 1) % M; // n!(mod M)
	}
	ifac[1000000] = mpow(fac[1000000], M - 2);
	for (ll i = 1000000; i > 0; i--) {
		ifac[i - 1] = ifac[i] * i%M;
	}
}
ll comb(ll a, ll b) {
	if (a == 0 && b == 0)return 1;
	if (a < b || a < 0)return 0;
	ll tmp = ifac[a - b] * ifac[b] % M;
	return tmp * fac[a] % M;
}
ll perm(ll a, ll b) {
	if (a == 0 && b == 0)return 1;
	if (a < b || a < 0)return 0;
	return fac[a] * ifac[a - b] % M;
}
long long modinv(long long a) {
	long long b = M, u = 1, v = 0;
	while (b) {
		long long t = a / b;
		a -= t * b; swap(a, b);
		u -= t * v; swap(u, v);
	}
	u %= M;
	if (u < 0) u += M;
	return u;
}
vector<vector<ll>> mul(vector<vector<ll>> a, vector<vector<ll>> b, int n) {
	int i, j, k, t;
	vector<vector<ll>> c(n);
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			t = 0;
			for (k = 0; k < n; k++)
				t = (t + a[i][k] * b[k][j] % M) % M;
			c[i].push_back(t);
		}
	}
	return c;
}

template< typename Monoid >
struct SegmentTree {
	using F = function< Monoid(Monoid, Monoid) >;

	int sz;
	vector< Monoid > seg;

	const F f;
	const Monoid M1;

	SegmentTree(int n, const F f, const Monoid &M1) : f(f), M1(M1) {
		sz = 1;
		while (sz < n) sz <<= 1;
		seg.assign(2 * sz, M1);
	}

	void set(int k, const Monoid &x) {
		seg[k + sz] = x;
	}

	void build() {
		for (int k = sz - 1; k > 0; k--) {
			seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
		}
	}

	void update(int k, const Monoid &x) {
		k += sz;
		seg[k] = x;
		while (k >>= 1) {
			seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
		}
	}

	Monoid query(int a, int b) {
		Monoid L = M1, R = M1;
		for (a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
			if (a & 1) L = f(L, seg[a++]);
			if (b & 1) R = f(seg[--b], R);
		}
		return f(L, R);
	}

	Monoid operator[](const int &k) const {
		return seg[k + sz];
	}

	template< typename C >
	int find_subtree(int a, const C &check, Monoid &M, bool type) {
		while (a < sz) {
			Monoid nxt = type ? f(seg[2 * a + type], M) : f(M, seg[2 * a + type]);
			if (check(nxt)) a = 2 * a + type;
			else M = nxt, a = 2 * a + 1 - type;
		}
		return a - sz;
	}


	template< typename C >
	int find_first(int a, const C &check) {
		Monoid L = M1;
		if (a <= 0) {
			if (check(f(L, seg[1]))) return find_subtree(1, check, L, false);
			return -1;
		}
		int b = sz;
		for (a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
			if (a & 1) {
				Monoid nxt = f(L, seg[a]);
				if (check(nxt)) return find_subtree(a, check, L, false);
				L = nxt;
				++a;
			}
		}
		return -1;
	}

	template< typename C >
	int find_last(int b, const C &check) {
		Monoid R = M1;
		if (b >= sz) {
			if (check(f(seg[1], R))) return find_subtree(1, check, R, true);
			return -1;
		}
		int a = sz;
		for (b += sz; a < b; a >>= 1, b >>= 1) {
			if (b & 1) {
				Monoid nxt = f(seg[--b], R);
				if (check(nxt)) return find_subtree(b, check, R, true);
				R = nxt;
			}
		}
		return -1;
	}
};

template< unsigned mod >
struct RollingHash {
	vector< unsigned > hashed, power;

	inline unsigned mul(unsigned a, unsigned b) const {
		unsigned long long x = (unsigned long long) a * b;
		unsigned xh = (unsigned)(x >> 32), xl = (unsigned)x, d, m;
		asm("divl %4; \n\t" : "=a" (d), "=d" (m) : "d" (xh), "a" (xl), "r" (mod));
		return m;
	}

	RollingHash(const string &s, unsigned base = 10007) {
		int sz = (int)s.size();
		hashed.assign(sz + 1, 0);
		power.assign(sz + 1, 0);
		power[0] = 1;
		for (int i = 0; i < sz; i++) {
			power[i + 1] = mul(power[i], base);
			hashed[i + 1] = mul(hashed[i], base) + s[i];
			if (hashed[i + 1] >= mod) hashed[i + 1] -= mod;
		}
	}

	unsigned get(int l, int r) const {
		unsigned ret = hashed[r] + mod - mul(hashed[l], power[r - l]);
		if (ret >= mod) ret -= mod;
		return ret;
	}

	unsigned connect(unsigned h1, int h2, int h2len) const {
		unsigned ret = mul(h1, power[h2len]) + h2;
		if (ret >= mod) ret -= mod;
		return ret;
	}

	int LCP(const RollingHash< mod > &b, int l1, int r1, int l2, int r2) {
		int len = min(r1 - l1, r2 - l2);
		int low = -1, high = len + 1;
		while (high - low > 1) {
			int mid = (low + high) / 2;
			if (get(l1, l1 + mid) == b.get(l2, l2 + mid)) low = mid;
			else high = mid;
		}
		return (low);
	}
};

using RH = RollingHash< 1000000007 >;

int main() {
	ll m,d[222222];
	cin >> m;
	for (; m > 0; m--) {
		ll n, t, a, b, i, j, ca = 0, cb = 0, c=0,ca2=0,cb2=0, p,k, ans = 0,ti;
		cin >> n >> t >> a >> b;
		vector<pair<ll,ll>> v;
		for (i = 0; i < n; i++) {
			cin >> d[i];
			if (d[i] == 0)
				ca++;
			else
				cb++;
		}
		for (i = 0; i < n; i++) {
			cin >> ti;
			v.push_back(make_pair(ti-1, d[i]));
		}
		v.push_back(make_pair(t, 0));
		sort(v.begin(), v.end());
		i = 0;
		while (i < n) {
			ll memo = v[i].first;
			p = memo - ca2 * a - cb2 * b;
			if (p >= 0) {
				k = i;
				k += min(p / a, ca);
				p -= min(p / a, ca)*a;
				k += min(p / b, cb);
				ans = max(ans, k);
			}
			while (1) {
				if (v[i].second == 0) {
					ca--;
					ca2++;
				}
				else {
					cb--;
					cb2++;
				}
				if (i + 1 < n) {
					if (v[i + 1].first == memo)
						i++;
					else
						break;
				}
				else
					break;
			}
			i++;
		}
		ll memo = v[i].first;
		p = memo - ca2 * a - cb2 * b;
		if (p >= 0) {
			k = i;
			k += min(p / a, ca);
			p -= min(p / a, ca)*a;
			k += min(p / b, cb);
			ans = max(ans, k);
		}
		cout << ans << endl;
	}
}