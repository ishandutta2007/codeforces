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
#define REP(i, l, r) for (ll i = l; i < (r); i++)
#define REP2(i, l, r) for (ll i = r - 1; i >= (l); i--)
template <class T>
using rque = priority_queue<T, vector<T>, greater<T>>;
const ll mod = 1e9+7;

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
};

ll M = 1000000007;

vector<ll> fac;  //n!(mod M)
vector<ll> ifac; //k!^{M-2} (mod M)

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
void setcomb(int sz = 2000010)
{
	fac.assign(sz, 0);
	ifac.assign(sz + 1, 0);
	fac[0] = 1;
	for (ll i = 0; i < sz; i++)
	{
		fac[i + 1] = fac[i] * (i + 1) % M; // n!(mod M)
	}
	ifac[sz] = mpow(fac[sz], M - 2);
	for (ll i = sz; i > 0; i--)
	{
		ifac[i - 1] = ifac[i] * i % M;
	}
}
ll comb(ll a, ll b)
{
	if(fac[0] == 0)
		setcomb();
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

struct UnionFind2
{
	ll p;
	vector<ll> data, val;
	vector<vector<pair<int,int>>> li;

	UnionFind2(vector<vector<pair<int, int>>> a, vector<ll> v, ll t)
	{
		int sz = a.size();
		li = a;
		rep(i, sz) data.pb(-(int)li[i].size() - 1);
		rep(i, sz) val.pb(v[i]);
		p = t;
	}

	bool unite(int x, int y)
	{
		x = find(x), y = find(y);
		if (x == y)
			return (false);
		if (data[x] > data[y])
			swap(x, y);
		while(!li[y].empty())
			li[x].pb(li[y].back()), li[y].pop_back();
		data[x] += data[y] + 1;
		data[y] = x;
		val[x] += val[y] - p;
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

	ll value(int k){
		return val[(find(k))];
	}
};

int main(){
	ll n, m, x;
	cin >> n >> m >> x;
	ll a[n];
	rep(i, n) cin >> a[i];
	ll u, v;
	vector<pair<ll, ll>> li;
	vector<pair<pair<ll, ll>, ll>> e;
	rep(i, m) cin >> u >> v, li.pb(mp(--u, --v));
	ll sum = 0;
	rep(i, n) sum += a[i];
	if(sum < (n-1)*x){
		cout << "NO" << endl;
		return 0;
	}
	UnionFind uf(n);
	rep(i, m) if (uf.unite(li[i].first, li[i].second)) e.pb(mp(mp(li[i].first, li[i].second), i + 1));
	cout << "YES\n";
	set<pair<ll, ll>> s;
	vector<vector<pair<int, int>>> li2(n);
	rep(i,n-1){
		ll a = e[i].first.first, b = e[i].first.second, idx = e[i].second;
		li2[a].pb(mp(b, idx));
		li2[b].pb(mp(a, idx));
	}
	rep(i, n) s.insert(mp(-a[i], i));
	vector<ll> val;
	rep(i, n) val.pb(a[i]);
	UnionFind2 uf2(li2, val, x);
	rep(i, n - 1){
		auto itr = s.begin();
		ll now = itr->second;
		s.erase(itr);
		while(!uf2.li[now].empty()){
			uf2.data[now]++;
			auto f = uf2.li[now].back();
			uf2.li[now].pop_back();
			ll mval = uf2.value(f.first), root = uf2.find(f.first);
			if (uf2.unite(now, root)){
				cout << f.second << "\n";
				s.erase(s.lower_bound(mp(-mval, root)));
				now = uf2.find(now);
				s.insert(mp(-uf2.value(now), now));
				break;
			}
		}
	}
}