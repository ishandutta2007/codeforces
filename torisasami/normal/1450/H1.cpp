#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb(x) push_back(x)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define lscan(x) scanf("%I64d", &x)
#define lprint(x) printf("%I64d", x)
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define rep2(i, n) for (ll i = n - 1; i >= 0; i--)
template <class T>
using rque = priority_queue<T, vector<T>, greater<T>>;
const ll mod = 998244353;

ll gcd(ll a, ll b)
{
	ll c = a % b;
	while (c != 0)
	{
		a = b;
		b = c;
		c = a % b;
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

	UnionFind(int sz)
	{
		data.assign(sz, -1);
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
};

ll M = 1000000007;

vector<ll> fac(2000011);  //n!(mod M)
vector<ll> ifac(2000011); //k!^{M-2} (mod M)

ll mpow(ll x, ll n)
{
	ll ans = 1;
	while (n != 0)
	{
		if (n & 1)
			ans = ans * x % M;
		x = x * x % M;
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
void setcomb()
{
	fac[0] = 1;
	ifac[0] = 1;
	for (ll i = 0; i < 2000010; i++)
	{
		fac[i + 1] = fac[i] * (i + 1) % M; // n!(mod M)
	}
	ifac[2000010] = mpow(fac[2000010], M - 2);
	for (ll i = 2000010; i > 0; i--)
	{
		ifac[i - 1] = ifac[i] * i % M;
	}
}
ll comb(ll a, ll b)
{
	if (a == 0 && b == 0)
		return 1;
	if (a < b || a < 0)
		return 0;
	ll tmp = ifac[a - b] * ifac[b] % M;
	return tmp * fac[a] % M;
}
ll perm(ll a, ll b)
{
	if (a == 0 && b == 0)
		return 1;
	if (a < b || a < 0)
		return 0;
	return fac[a] * ifac[a - b] % M;
}
long long modinv(long long a)
{
	long long b = M, u = 1, v = 0;
	while (b)
	{
		long long t = a / b;
		a -= t * b;
		swap(a, b);
		u -= t * v;
		swap(u, v);
	}
	u %= M;
	if (u < 0)
		u += M;
	return u;
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

using mint = ModInt<mod>;

typedef vector<vector<mint>> Matrix;

Matrix mul(Matrix a, Matrix b)
{
	assert(a[0].size() == b.size());
	int i, j, k;
	int n = a.size(), m = b[0].size(), l = a[0].size();
	Matrix c(n, vector<mint>(m));
	for (i = 0; i < n; i++)
		for (k = 0; k < l; k++)
			for (j = 0; j < m; j++)
				c[i][j] += a[i][k] * b[k][j];
	return c;
}

Matrix mat_pow(Matrix x, ll n)
{
	ll k = x.size();
	Matrix ans(k, vector<mint>(k, 0));
	for (int i = 0; i < k; i++)
		ans[i][i] = 1;
	while (n != 0)
	{
		if (n & 1)
			ans = mul(ans, x);
		x = mul(x, x);
		n = n >> 1;
	}
	return ans;
}

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

int main(){
	M = 998244353;
	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	setcomb();
	int cnt = 0;
	rep(i, n) if (s[i] == 'b') cnt += 1 - (i % 2) * 2;
	int c[2] = {};
	rep(i, n) if (s[i] == '?') c[i % 2]++;
	vector<mint> a(c[0]+1), b(c[1]+1);
	rep(i, c[0] + 1) a[i] = comb(c[0], i);
	rep(i, c[1] + 1) b[c[1] - i] = comb(c[1], i);
	NTT ntt;
	auto res = ntt.multiply(a, b);
	mint ans = 0;
	rep(i, res.size()){
		if(abs(cnt+i-c[1])%2 == 0)
			ans += res[i] * (abs(cnt + i - c[1]) / 2);
	}
	ans /= mpow(2, c[0] + c[1] - 1);
	cout << ans << endl;
}