#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb(x) emplace_back(x)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define lscan(x) scanf("%I64d", &x)
#define lprint(x) printf("%I64d", x)
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define rep2(i, n) for (ll i = (ll)n - 1; i >= 0; i--)
#define REP(i, l, r) for (ll i = l; i < (r); i++)
#define REP2(i, l, r) for (ll i = (ll)r - 1; i >= (l); i--)
#define siz(x) (ll)x.size()
template <class T>
using rque = priority_queue<T, vector<T>, greater<T>>;

template <class T>
bool chmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return 1;
    }
    return 0;
}

template <class T>
bool chmax(T &a, const T &b) {
    if (b > a) {
        a = b;
        return 1;
    }
    return 0;
}

ll gcd(ll a, ll b)
{
	if(a == 0)
		return b;
	if(b == 0)
		return a;
	ll cnt = a % b;
	while (cnt != 0)
	{
		a = b;
		b = cnt;
		cnt = a % b;
	}
	return b;
}

long long extGCD(long long a, long long b, long long &x, long long &y)
{
	if (b == 0)
	{
		x = 1;
		y = 0;
		return a;
	}
	long long d = extGCD(b, a % b, y, x);
	y -= a / b * x;
	return d;
}

struct UnionFind
{
	vector<ll> data;
	int num;

	UnionFind(int sz)
	{
		data.assign(sz, -1);
		num = sz;
	}

	bool unite(int x, int y)
	{
		x = find(x), y = find(y);
		if (x == y)
			return (false);
		if (data[x] > data[y])
			swap(x, y);
		data[x] += data[y];
		data[y] = x;
		num--;
		return (true);
	}

	int find(int k)
	{
		if (data[k] < 0)
			return (k);
		return (data[k] = find(data[k]));
	}

	ll size(int k)
	{
		return (-data[find(k)]);
	}

	bool same(int x, int y){
		return find(x) == find(y);
	}
};

template <int mod>
struct ModInt
{
	int x;

	ModInt() : x(0) {}

	ModInt(int64_t y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}

	ModInt &operator+=(const ModInt &p)
	{
		if ((x += p.x) >= mod)
			x -= mod;
		return *this;
	}

	ModInt &operator-=(const ModInt &p)
	{
		if ((x += mod - p.x) >= mod)
			x -= mod;
		return *this;
	}

	ModInt &operator*=(const ModInt &p)
	{
		x = (int)(1LL * x * p.x % mod);
		return *this;
	}

	ModInt &operator/=(const ModInt &p)
	{
		*this *= p.inverse();
		return *this;
	}

	ModInt operator-() const { return ModInt(-x); }

	ModInt operator+(const ModInt &p) const { return ModInt(*this) += p; }

	ModInt operator-(const ModInt &p) const { return ModInt(*this) -= p; }

	ModInt operator*(const ModInt &p) const { return ModInt(*this) *= p; }

	ModInt operator/(const ModInt &p) const { return ModInt(*this) /= p; }

	bool operator==(const ModInt &p) const { return x == p.x; }

	bool operator!=(const ModInt &p) const { return x != p.x; }

	ModInt inverse() const
	{
		int a = x, b = mod, u = 1, v = 0, t;
		while (b > 0)
		{
			t = a / b;
			swap(a -= t * b, b);
			swap(u -= t * v, v);
		}
		return ModInt(u);
	}

	ModInt pow(int64_t n) const
	{
		ModInt ret(1), mul(x);
		while (n > 0)
		{
			if (n & 1)
				ret *= mul;
			mul *= mul;
			n >>= 1;
		}
		return ret;
	}

	friend ostream &operator<<(ostream &os, const ModInt &p)
	{
		return os << p.x;
	}

	friend istream &operator>>(istream &is, ModInt &a)
	{
		int64_t t;
		is >> t;
		a = ModInt<mod>(t);
		return (is);
	}

	static int get_mod() { return mod; }
};

// ----- library -------
template <typename Monoid>
struct SegmentTree
{
    using F = function<Monoid(Monoid, Monoid)>;

    int sz;
    vector<Monoid> seg;

    const F f;
    const Monoid M1;

    SegmentTree(int n, const F f, const Monoid &M1) : f(f), M1(M1)
    {
        sz = 1;
        while (sz < n)
            sz <<= 1;
        seg.assign(2 * sz, M1);
    }

    void set(int k, const Monoid &x)
    {
        seg[k + sz] = x;
    }

    void build()
    {
        for (int k = sz - 1; k > 0; k--)
        {
            seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
        }
    }

    void update(int k, const Monoid &x)
    {
        k += sz;
        seg[k] = x;
        while (k >>= 1)
        {
            seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
        }
    }

    Monoid query(int a, int b)
    {
        Monoid L = M1, R = M1;
        for (a += sz, b += sz; a < b; a >>= 1, b >>= 1)
        {
            if (a & 1)
                L = f(L, seg[a++]);
            if (b & 1)
                R = f(seg[--b], R);
        }
        return f(L, R);
    }

    Monoid operator[](const int &k) const
    {
        return seg[k + sz];
    }

    template <typename C>
    int find_subtree(int a, const C &check, Monoid &M, bool type)
    {
        while (a < sz)
        {
            Monoid nxt = type ? f(seg[2 * a + type], M) : f(M, seg[2 * a + type]);
            if (check(nxt))
                a = 2 * a + type;
            else
                M = nxt, a = 2 * a + 1 - type;
        }
        return a - sz;
    }

    template <typename C>
    int find_first(int a, const C &check)
    {
        Monoid L = M1;
        if (a <= 0)
        {
            if (check(f(L, seg[1])))
                return find_subtree(1, check, L, false);
            return -1;
        }
        int b = sz;
        for (a += sz, b += sz; a < b; a >>= 1, b >>= 1)
        {
            if (a & 1)
            {
                Monoid nxt = f(L, seg[a]);
                if (check(nxt))
                    return find_subtree(a, check, L, false);
                L = nxt;
                ++a;
            }
        }
        return -1;
    }

    template <typename C>
    int find_last(int b, const C &check)
    {
        Monoid R = M1;
        if (b >= sz)
        {
            if (check(f(seg[1], R)))
                return find_subtree(1, check, R, true);
            return -1;
        }
        int a = sz;
        for (b += sz; a < b; a >>= 1, b >>= 1)
        {
            if (b & 1)
            {
                Monoid nxt = f(seg[--b], R);
                if (check(nxt))
                    return find_subtree(b, check, R, true);
                R = nxt;
            }
        }
        return -1;
    }
};
// ----- library -------

// constexpr int mod = 1000000007;
constexpr int mod = 998244353;
// constexpr int mod = 31607;
using mint = ModInt<mod>;
mint mpow(mint x, ll n)
{
	mint ans = 1;
	while (n != 0)
	{
		if (n & 1)
			ans *= x;
		x *= x;
		n = n >> 1;
	}
	return ans;
}
ll mpow2(ll x, ll n, ll mod)
{
	ll ans = 1;
	while (n != 0)
	{
		if (n & 1)
			ans = ans * x % mod;
		x = x * x % mod;
		n = n >> 1;
	}
	return ans;
}
vector<mint> fac;
vector<mint> ifac;
void setcomb(int sz = 2000010)
{
	fac.assign(sz + 1, 0);
	ifac.assign(sz + 1, 0);
	fac[0] = 1;
	for (ll i = 0; i < sz; i++)
	{
		fac[i + 1] = fac[i] * (i + 1); // n!(mod M)
	}
	ifac[sz] = fac[sz].inverse();
	for (ll i = sz; i > 0; i--)
	{
		ifac[i - 1] = ifac[i] * i;
	}
}
mint comb(ll a, ll b)
{
	if(fac.size() == 0)
		setcomb();
	if (a == 0 && b == 0)
		return 1;
	if (a < b || a < 0 || b < 0)
		return 0;
	return ifac[a - b] * ifac[b] * fac[a];
}
mint perm(ll a, ll b)
{
	if(fac.size() == 0)
		setcomb();
	if (a == 0 && b == 0)
		return 1;
	if (a < b || a < 0)
		return 0;
	return fac[a] * ifac[a - b];
}
ll modinv2(ll a, ll mod)
{
	ll b = mod, u = 1, v = 0;
	while (b)
	{
		ll t = a / b;
		a -= t * b;
		swap(a, b);
		u -= t * v;
		swap(u, v);
	}
	u %= mod;
	if (u < 0)
		u += mod;
	return u;
}

using P = pair<mint, mint>;
int main()
{
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	cout << fixed << setprecision(15);

	ll n, q;
	cin >> n >> q;
	ll p[n];
	rep(i, n) cin >> p[i];
	SegmentTree<P> seg(n, [](P a, P b){ return mp(a.first * b.first, a.second * b.first + b.second); }, {1, 0});
	rep(i, n) seg.set(i, {(mint)100 / p[i], (mint)100 / p[i]});
	seg.build();
	mint ans = seg.query(0, n).second;
	set<ll> s, rs;
	s.insert(n);
	rs.insert(0);
	while(q--){
		ll u;
		cin >> u;
		u--;
		ll r = *s.lower_bound(u), l = -(*rs.lower_bound(-u));
		if(r == u){
			s.erase(u);
			rs.erase(-u);
			r = *s.lower_bound(u), l = -(*rs.lower_bound(-u));
			ans += seg.query(l, r).second;
			ans -= seg.query(l, u).second;
			ans -= seg.query(u, r).second;
		}
		else{
			ans -= seg.query(l, r).second;
			ans += seg.query(l, u).second;
			ans += seg.query(u, r).second;
			s.insert(u);
			rs.insert(-u);
		}
		cout << ans << '\n';
	}
}