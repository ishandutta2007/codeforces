#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb(x) push_back(x)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define lscan(x) scanf("%I64d", &x)
#define lprint(x) printf("%I64d", x)
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
vector<vector<ll>> mul(vector<vector<ll>> a, vector<vector<ll>> b, int n)
{
	int i, j, k, t;
	vector<vector<ll>> c(n);
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			t = 0;
			for (k = 0; k < n; k++)
				t = (t + a[i][k] * b[k][j] % M) % M;
			c[i].push_back(t);
		}
	}
	return c;
}

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

template <unsigned mod>
struct RollingHash
{
	vector<unsigned> hashed, power;

	inline unsigned mul(unsigned a, unsigned b) const
	{
		unsigned long long x = (unsigned long long)a * b;
		unsigned xh = (unsigned)(x >> 32), xl = (unsigned)x, d, m;
		asm("divl %4; \n\t"
			: "=a"(d), "=d"(m)
			: "d"(xh), "a"(xl), "r"(mod));
		return m;
	}

	RollingHash(const string &s, unsigned base = 10007)
	{
		int sz = (int)s.size();
		hashed.assign(sz + 1, 0);
		power.assign(sz + 1, 0);
		power[0] = 1;
		for (int i = 0; i < sz; i++)
		{
			power[i + 1] = mul(power[i], base);
			hashed[i + 1] = mul(hashed[i], base) + s[i];
			if (hashed[i + 1] >= mod)
				hashed[i + 1] -= mod;
		}
	}

	unsigned get(int l, int r) const
	{
		unsigned ret = hashed[r] + mod - mul(hashed[l], power[r - l]);
		if (ret >= mod)
			ret -= mod;
		return ret;
	}

	unsigned connect(unsigned h1, int h2, int h2len) const
	{
		unsigned ret = mul(h1, power[h2len]) + h2;
		if (ret >= mod)
			ret -= mod;
		return ret;
	}

	int LCP(const RollingHash<mod> &b, int l1, int r1, int l2, int r2)
	{
		int len = min(r1 - l1, r2 - l2);
		int low = -1, high = len + 1;
		while (high - low > 1)
		{
			int mid = (low + high) / 2;
			if (get(l1, l1 + mid) == b.get(l2, l2 + mid))
				low = mid;
			else
				high = mid;
		}
		return (low);
	}
};

using RH = RollingHash<1000000007>;

template <typename T>
struct edge
{
	int src, to;
	T cost;

	edge(int to, T cost) : src(-1), to(to), cost(cost) {}

	edge(int src, int to, T cost) : src(src), to(to), cost(cost) {}

	edge &operator=(const int &x)
	{
		to = x;
		return *this;
	}

	operator int() const { return to; }
};

template <typename T>
using Edges = vector<edge<T>>;
template <typename T>
using WeightedGraph = vector<Edges<T>>;
using UnWeightedGraph = vector<vector<int>>;
template <typename T>
using Matrix = vector<vector<T>>;

template <typename G>
struct DoublingLowestCommonAncestor
{
	const int LOG;
	vector<int> dep;
	const G &g;
	vector<vector<int>> table;

	DoublingLowestCommonAncestor(const G &g) : g(g), dep(g.size()), LOG(32 - __builtin_clz(g.size()))
	{
		table.assign(LOG, vector<int>(g.size(), -1));
	}

	void dfs(int idx, int par, int d)
	{
		table[0][idx] = par;
		dep[idx] = d;
		for (auto &to : g[idx])
		{
			if (to != par)
				dfs(to, idx, d + 1);
		}
	}

	void build()
	{
		dfs(0, -1, 0);
		for (int k = 0; k + 1 < LOG; k++)
		{
			for (int i = 0; i < table[k].size(); i++)
			{
				if (table[k][i] == -1)
					table[k + 1][i] = -1;
				else
					table[k + 1][i] = table[k][table[k][i]];
			}
		}
	}

	int query(int u, int v)
	{
		if (dep[u] > dep[v])
			swap(u, v);
		for (int i = LOG - 1; i >= 0; i--)
		{
			if (((dep[v] - dep[u]) >> i) & 1)
				v = table[i][v];
		}
		if (u == v)
			return u;
		for (int i = LOG - 1; i >= 0; i--)
		{
			if (table[i][u] != table[i][v])
			{
				u = table[i][u];
				v = table[i][v];
			}
		}
		return table[0][u];
	}
};

vector<int> li[111111];
vector<int> li2[111111];
UnWeightedGraph g(111111);
int d[111111], pa[111111];

void dfs(int now, int par){
	pa[now] = par;
	for (auto &e : li[now]){
		if(e!=par){
			if(d[e]==-1){
				d[e] = d[now] + 1;
				g[now].pb(e);
				dfs(e, now);
			}
			else
				li2[now].pb(e);
		}
	}
}

int main(){
	int k, n, m, i, u, v, mi = 1e9;
	cin >> n >> m >> k;	
	for (i = 0; i < m; i++){
		cin >> u >> v;
		u--;
		v--;
		li[u].pb(v);
		li[v].pb(u);
	}
	for (i = 0; i < n;i++)
		d[i] = -1;
	d[0] = 0;
	dfs(0, -1);
	DoublingLowestCommonAncestor<UnWeightedGraph> lca(g);
	lca.build();
	int c[111111] = {}, cnt[2] = {};
	int p, q;
	for (i = 0; i < n; i++)
		cnt[d[i] % 2]++;
	for (i = 0; i < n; i++){
		for(auto &e:li2[i]){
			if(d[i]%2==d[e]%2&&c[i]==0&&c[e]==0){
				cnt[d[i] % 2]--;
				c[e]++;
			}
			int an = lca.query(i, e);
			if (d[i] + d[e] - d[an] * 2 + 1 < mi){
				mi = d[i] + d[e] - d[an] * 2 + 1;
				p = i;
				q = e;
			}
		}
	}
	if(mi<=k){
		int an = lca.query(p, q);
		vector<int> v1, v2;
		int now = p;
		while(1){
			v1.pb(now);
			if(now==an)
				break;
			now = pa[now];
		}
		now = q;
		while (1){
			if(now==an)
				break;
			v2.pb(now);
			now = pa[now];
		}
		reverse(all(v2));
		v1.insert(v1.end(), all(v2));
		cout << "2" << endl;
		cout << v1.size() << endl;
		cout << v1[0] + 1;
		for (i = 1; i < v1.size();i++)
			cout << " " << v1[i] + 1;
		cout << endl;
	}
	else{
		cout << "1" << endl;
		int flag = 0;
		if (cnt[0] > cnt[1]){
			int cn = 0, tar=k/2;
			if(k%2==1)
				tar++;
			for (i = 0; i < n && cn < tar;i++){
				if(d[i]%2==0&&c[i]==0){
					if(flag)
						cout << " ";
					else
						flag++;
					cout << i + 1;
					cn++;
				}
			}
			cout << endl;
		}
		else{
			int cn = 0, tar = k / 2;
			if (k % 2 == 1)
				tar++;
			for (i = 0; i < n && cn < tar; i++){
				if (d[i] % 2 == 1 && c[i] == 0){
					if (flag)
						cout << " ";
					else
						flag++;
					cout << i + 1;
					cn++;
				}
			}
			cout << endl;
		}
	}
}