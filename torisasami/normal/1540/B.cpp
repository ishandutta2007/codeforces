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
#define rep2(i, n) for (ll i = (ll)n - 1; i >= 0; i--)
#define REP(i, l, r) for (ll i = l; i < (r); i++)
#define REP2(i, l, r) for (ll i = (ll)r - 1; i >= (l); i--)
#define siz(x) (ll)x.size()
template <class T>
using rque = priority_queue<T, vector<T>, greater<T>>;
const ll mod = (int)1e9 + 7;

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

ll M = 1000000007;

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

int main(){
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	ll n;
	cin >> n;
	mint dp[200][200];
	rep(i,n) rep(j,n){
		if(i == 0)
			dp[i][j] = 0;
		else if(j == 0)
			dp[i][j] = 1;
		else
			dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) / 2;
	}
	ll u, v;
	vector<ll> li[n];
	rep(i, n - 1) cin >> u >> v, li[--u].pb(--v), li[v].pb(u);
	mint ans = 0;
	function<pair<unordered_map<int, int>, int>(int, int, int, int)> dfs = [&](int now, int par, int s, int dep){
		unordered_map<int, int> m;
		int sz = 1;
		vector<pair<unordered_map<int, int>, int>> vec;
		for (auto e : li[now]){
			if(e != par){
				auto res = dfs(e, now, s, dep + 1);
				sz += res.second;
				vec.pb(res);
			}
		}
		for(auto e: vec){
			int nsz = sz - e.second;
			for (auto d : e.first){
				ans += dp[dep][d.first - dep] * nsz * d.second;
				m[d.first] += d.second;
			}
		}
		if(now > s){
			ans += sz;
			m[dep]++;
		}
		return mp(m, sz);
	};
	rep(i, n) dfs(i, -1, i, 0);
	ans /= n;
	cout << ans << endl;
}