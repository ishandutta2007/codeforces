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
// ----- library -------

// constexpr int mod = 1000000007;
constexpr int mod = 998244353;
// constexpr int mod = 31607;
using mint = ModInt<mod>;
template <int mod>
struct NumberTheoreticTransform
{

    vector<int> rev, rts;
    int base, max_base, root;

    NumberTheoreticTransform() : base(1), rev{0, 1}, rts{0, 1}
    {
        assert(mod >= 3 && mod % 2 == 1);
        auto tmp = mod - 1;
        max_base = 0;
        while (tmp % 2 == 0)
            tmp >>= 1, max_base++;
        root = 2;
        while (mod_pow(root, (mod - 1) >> 1) == 1)
            ++root;
        assert(mod_pow(root, mod - 1) == 1);
        root = mod_pow(root, (mod - 1) >> max_base);
    }

    inline int mod_pow(int x, int n)
    {
        int ret = 1;
        while (n > 0)
        {
            if (n & 1)
                ret = mul(ret, x);
            x = mul(x, x);
            n >>= 1;
        }
        return ret;
    }

    inline int inverse(int x)
    {
        return mod_pow(x, mod - 2);
    }

    inline unsigned add(unsigned x, unsigned y)
    {
        x += y;
        if (x >= mod)
            x -= mod;
        return x;
    }

    inline unsigned mul(unsigned a, unsigned b)
    {
        return 1ull * a * b % (unsigned long long)mod;
    }

    void ensure_base(int nbase)
    {
        if (nbase <= base)
            return;
        rev.resize(1 << nbase);
        rts.resize(1 << nbase);
        for (int i = 0; i < (1 << nbase); i++)
        {
            rev[i] = (rev[i >> 1] >> 1) + ((i & 1) << (nbase - 1));
        }
        assert(nbase <= max_base);
        while (base < nbase)
        {
            int z = mod_pow(root, 1 << (max_base - 1 - base));
            for (int i = 1 << (base - 1); i < (1 << base); i++)
            {
                rts[i << 1] = rts[i];
                rts[(i << 1) + 1] = mul(rts[i], z);
            }
            ++base;
        }
    }

    void ntt(vector<mint> &a)
    {
        const int n = (int)a.size();
        assert((n & (n - 1)) == 0);
        int zeros = __builtin_ctz(n);
        ensure_base(zeros);
        int shift = base - zeros;
        for (int i = 0; i < n; i++)
        {
            if (i < (rev[i] >> shift))
            {
                swap(a[i], a[rev[i] >> shift]);
            }
        }
        for (int k = 1; k < n; k <<= 1)
        {
            for (int i = 0; i < n; i += 2 * k)
            {
                for (int j = 0; j < k; j++)
                {
                    mint z = a[i + j + k] * rts[j + k];
                    a[i + j + k] = a[i + j] - z;
                    a[i + j] = a[i + j] + z;
                }
            }
        }
    }

    vector<mint> multiply(vector<mint> a, vector<mint> b)
    {
        int need = a.size() + b.size() - 1;
        int nbase = 1;
        while ((1 << nbase) < need)
            nbase++;
        ensure_base(nbase);
        int sz = 1 << nbase;
        a.resize(sz, 0);
        b.resize(sz, 0);
        ntt(a);
        ntt(b);
        mint inv_sz = inverse(sz);
        for (int i = 0; i < sz; i++)
        {
            a[i] = a[i] * b[i] * inv_sz;
        }
        reverse(a.begin() + 1, a.end());
        ntt(a);
        a.resize(need);
        return a;
    }
};
using NTT = NumberTheoreticTransform<mod>;
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

int main(){
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	cout << fixed << setprecision(15);

	ll n;
	cin >> n;
	NTT ntt;
	vector<mint> a(n), b(n);
	rep(i, n) a[i] = comb(n, i + 1) * mpow(3, n - i - 1), b[i] = a[i];
	auto res = ntt.multiply(a, b);
	mint ans = 0;
	rep(i,n){
		mint p = -mpow(3, i), r;
		if(i % 2)
			r = comb(n, i);
		else
			r = -comb(n, i);
		ans += (mpow(p + 1, n) - mpow(p, n)) * r;
	}
	ans *= 3;
	// cout << ans << endl;
	REP(i,1,n+1){
		if(i%2)
			ans += comb(n, i) * 2 * mpow(3, n * (n - i) + i);
		else
			ans -= comb(n, i) * 2 * mpow(3, n * (n - i) + i);
	}
	cout << ans << endl;
}