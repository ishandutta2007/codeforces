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
template<int mod, int primitive_root>
struct Number_Theorem_Transform{
    using T = ModInt<mod>;
    vector<T> r, ir;

    Number_Theorem_Transform(){
        r.resize(30), ir.resize(30);
        for(int i = 0; i < 30; i++){
            r[i] = -T(primitive_root).pow((mod-1)>>(i+2)); //r[i]:=12^(i+2)
            ir[i] = r[i].inverse(); //ir[i]:=1/r[i]
        }
    }

    void ntt(vector<T> &a, int n) const{
        assert((n&(n-1)) == 0);
        a.resize(n);
        for(int k = n; k >>= 1;){
            T w = 1;
            for(int s = 0, t = 0; s < n; s += 2*k){
                for(int i = s, j = s+k; i < s+k; i++, j++){
                    T x = a[i], y = w*a[j];
                    a[i] = x+y, a[j] = x-y;
                }
                w *= r[__builtin_ctz(++t)];
            }
        }
    }

    void intt(vector<T> &a, int n) const{
        assert((n&(n-1)) == 0);
        a.resize(n);
        for(int k = 1; k < n; k <<= 1){
            T w = 1;
            for(int s = 0, t = 0; s < n; s += 2*k){
                for(int i = s, j = s+k; i < s+k; i++, j++){
                    T x = a[i], y = a[j];
                    a[i] = x+y, a[j] = w*(x-y);
                }
                w *= ir[__builtin_ctz(++t)];
            }
        }
        T inv = T(n).inverse();
        for(auto &e: a) e *= inv;
    }

    vector<T> convolve(vector<T> a, vector<T> b) const{
        int k = (int)a.size()+(int)b.size()-1, n = 1;
        while(n < k) n <<= 1;
        ntt(a, n), ntt(b, n);
        for(int i = 0; i < n; i++) a[i] *= b[i];
        intt(a, n), a.resize(k);
        return a;
    }
};

const int m1 = 1045430273, r1 = 3;
const int m2 = 1051721729, r2 = 6;
const int m3 = 1053818881, r3 = 7;
// ----- library -------

constexpr int mod = 1000000007;
// constexpr int mod = 998244353;
// constexpr int mod = 31607;
using mint = ModInt<mod>;
template<int mod>
struct Arbitrary_Mod_Number_Theorem_Transform{
    using T = ModInt<mod>;
    using mint1 = ModInt<m1>;
    using mint2 = ModInt<m2>;
    using mint3 = ModInt<m3>;
    Number_Theorem_Transform<m1, r1> ntt1;
    Number_Theorem_Transform<m2, r2> ntt2;
    Number_Theorem_Transform<m3, r3> ntt3;

    Arbitrary_Mod_Number_Theorem_Transform() {}

    vector<T> convolve(const vector<T> &a, const vector<T> &b){
        int n = a.size(), m = b.size();
        vector<mint1> a1(n), b1(m);
        vector<mint2> a2(n), b2(m);
        vector<mint3> a3(n), b3(m);
        for(int i = 0; i < n; i++) a1[i] = a[i].x, a2[i] = a[i].x, a3[i] = a[i].x;
        for(int i = 0; i < m; i++) b1[i] = b[i].x, b2[i] = b[i].x, b3[i] = b[i].x;
        auto x = ntt1.convolve(a1, b1);
        auto y = ntt2.convolve(a2, b2);
        auto z = ntt3.convolve(a3, b3);
        const auto m1_inv_m2 = mint2(m1).inverse().x;
        const auto m1m2_inv_m3 = (mint3(m1)*m2).inverse().x;
        const auto m1m2_mod = (mint(m1)*m2).x;
        vector<T> ret(n+m-1);
        for(int i = 0; i < n+m-1; i++){
            auto v1 = ((mint2(y[i])+m2-x[i].x)*m1_inv_m2).x;
            auto v2 = ((z[i]+m3-x[i].x-mint3(m1)*v1)*m1m2_inv_m3).x;
            ret[i] = (T(x[i].x))+T(m1)*v1+T(m1m2_mod)*v2;
        }
        return ret;
    }
};
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

	ll f, w, h;
	cin >> f >> w >> h;
	mint ans = 0;
	REP(i, 1, w + 1){
		if(i * (h+1) > w || i - 1 > f)
			break;
		mint res = comb(w - i * h - 1, i - 1);
		ans += res * comb(f + 1, i);
	}
	mint sum = 0;
	REP(i, 1, w + 1){
		if(i - 1 > f)
			break;
		mint res = comb(w - 1, i - 1);
		sum += res * comb(f + 1, i);
	}
	if(w == 0){
		ans = 1;
		sum = 1;
	}
	cout << ans / sum << endl;
}