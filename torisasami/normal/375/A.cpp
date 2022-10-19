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
#define llsize(x) (ll)x.size()
template <class T>
using rque = priority_queue<T, vector<T>, greater<T>>;
const ll mod = 998244353;

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

struct query{
    int l, r, id;
    query(int l, int r, int id) : l(l), r(r), id(id) {}
};
 
template<typename T, typename Q> //TQ
struct Mo{
    vector<T> a;
    const int n;
    int l, r;
    Q ans;
	vector<int> cnt;

	Mo(vector<T> a) : a(a), n(a.size()), l(0), r(0), ans(0), cnt(a.size(), 0) {}
 
    void insert(int x){
        if(cnt[a[x]]++ == 0)
			ans++;
	}

	void insert_left(int x){
        
    }

    void insert_right(int x){
        
    }

    void erase(int x){
        if(--cnt[a[x]] == 0)
			ans--;
    }

    void erase_left(int x){
        
    }

    void erase_right(int x){
        
    }

    vector<Q> solve(int bucket_size, vector<query> qs){
        vector<Q> ret(qs.size());
        sort(begin(qs), end(qs), [&](query a, query b){
            int A = (a.l)/bucket_size, B = (b.l)/bucket_size;
            if(A != B) return A < B;
            if(A%2 == 0) return a.r < b.r;
            return a.r > b.r;
        });
        for(auto &e: qs){
            while(e.l < l) insert(--l);
            while(r < e.r) insert(r++);
            while(l < e.l) erase(l++);
            while(e.r < r) erase(--r);
            ret[e.id] = ans;
        }
        return ret;
    }
};

int main(){
	string s;
	cin >> s;
	ll f[10] = {};
	f[1] = 1;
	f[6] = 1;
	f[8] = 1;
	f[9] = 1;
	ll n = s.length();
	vector<ll> v;
	rep(i, n){
		if(f[s[i]-'0'])
			f[s[i] - '0'] = 0;
		else
			v.pb(s[i] - '0');
	}
	ll p = 0, r = 1;
	vector<ll> v2;
	v2.pb(1);
	v2.pb(6);
	v2.pb(8);
	v2.pb(9);
	rep2(i, v.size()) p += v[i] * r, p %= 7, r *= 10, r %= 7;
	do{
		ll p2 = 0, r2 = 1;
		rep2(i, 4) p2 += v2[i] * r2, p2 %= 7, r2 *= 10, r2 %= 7;
		if((p + p2 * r) % 7 == 0){
			rep(i, 4) cout << v2[i];
			rep(i, v.size()) cout << v[i];
			cout << endl;
			return 0;
		}
	} while (next_permutation(all(v2)));
}