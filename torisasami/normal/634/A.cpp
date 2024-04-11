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
const int mod = 998244353;
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

vector<vector<mint>> mul(vector<vector<mint>> a, vector<vector<mint>> b)
{
	int i, j, k;
	mint t;
	int n = a.size(), m = b[0].size(), l = a[0].size();
	vector<vector<mint>> c(n, vector<mint>(m));
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			t = 0;
			for (k = 0; k < l; k++)
				t += a[i][k] * b[k][j];
			c[i][j] = t;
		}
	}
	return c;
}

vector<vector<mint>> mat_pow(vector<vector<mint>> x, ll n)
{
	ll k = x.size();
	vector<vector<mint>> ans(k, vector<mint>(k, 0));
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

template <typename Monoid, typename OperatorMonoid = Monoid>
struct LazySegmentTree
{
	using F = function<Monoid(Monoid, Monoid)>;
	using G = function<Monoid(Monoid, OperatorMonoid)>;
	using H = function<OperatorMonoid(OperatorMonoid, OperatorMonoid)>;

	int sz, height;
	vector<Monoid> data;
	vector<OperatorMonoid> lazy;
	const F f;
	const G g;
	const H h;
	const Monoid M1;
	const OperatorMonoid OM0;

	LazySegmentTree(int n, const F f, const G g, const H h,
					const Monoid &M1, const OperatorMonoid OM0)
		: f(f), g(g), h(h), M1(M1), OM0(OM0)
	{
		sz = 1;
		height = 0;
		while (sz < n)
			sz <<= 1, height++;
		data.assign(2 * sz, M1);
		lazy.assign(2 * sz, OM0);
	}

	void set(int k, const Monoid &x)
	{
		data[k + sz] = x;
	}

	void build()
	{
		for (int k = sz - 1; k > 0; k--)
		{
			data[k] = f(data[2 * k + 0], data[2 * k + 1]);
		}
	}

	inline void propagate(int k)
	{
		if (lazy[k] != OM0)
		{
			lazy[2 * k + 0] = h(lazy[2 * k + 0], lazy[k]);
			lazy[2 * k + 1] = h(lazy[2 * k + 1], lazy[k]);
			data[k] = reflect(k);
			lazy[k] = OM0;
		}
	}

	inline Monoid reflect(int k)
	{
		return lazy[k] == OM0 ? data[k] : g(data[k], lazy[k]);
	}

	inline void recalc(int k)
	{
		while (k >>= 1)
			data[k] = f(reflect(2 * k + 0), reflect(2 * k + 1));
	}

	inline void thrust(int k)
	{
		for (int i = height; i > 0; i--)
			propagate(k >> i);
	}

	void update(int a, int b, const OperatorMonoid &x)
	{
		thrust(a += sz);
		thrust(b += sz - 1);
		for (int l = a, r = b + 1; l < r; l >>= 1, r >>= 1)
		{
			if (l & 1)
				lazy[l] = h(lazy[l], x), ++l;
			if (r & 1)
				--r, lazy[r] = h(lazy[r], x);
		}
		recalc(a);
		recalc(b);
	}

	Monoid query(int a, int b)
	{
		thrust(a += sz);
		thrust(b += sz - 1);
		Monoid L = M1, R = M1;
		for (int l = a, r = b + 1; l < r; l >>= 1, r >>= 1)
		{
			if (l & 1)
				L = f(L, reflect(l++));
			if (r & 1)
				R = f(reflect(--r), R);
		}
		return f(L, R);
	}

	Monoid operator[](const int &k)
	{
		return query(k, k + 1);
	}

	template <typename C>
	int find_subtree(int a, const C &check, Monoid &M, bool type)
	{
		while (a < sz)
		{
			propagate(a);
			Monoid nxt = type ? f(reflect(2 * a + type), M) : f(M, reflect(2 * a + type));
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
			if (check(f(L, reflect(1))))
				return find_subtree(1, check, L, false);
			return -1;
		}
		thrust(a + sz);
		int b = sz;
		for (a += sz, b += sz; a < b; a >>= 1, b >>= 1)
		{
			if (a & 1)
			{
				Monoid nxt = f(L, reflect(a));
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
			if (check(f(reflect(1), R)))
				return find_subtree(1, check, R, true);
			return -1;
		}
		thrust(b + sz - 1);
		int a = sz;
		for (b += sz; a < b; a >>= 1, b >>= 1)
		{
			if (b & 1)
			{
				Monoid nxt = f(reflect(--b), R);
				if (check(nxt))
					return find_subtree(b, check, R, true);
				R = nxt;
			}
		}
		return -1;
	}
};

template <typename flow_t, typename cost_t>
struct PrimalDual
{
	const cost_t INF;

	struct edge
	{
		int to;
		flow_t cap;
		cost_t cost;
		int rev;
		bool isrev;
	};
	vector<vector<edge>> graph;
	vector<cost_t> potential, min_cost;
	vector<int> prevv, preve;

	PrimalDual(int V) : graph(V), INF(numeric_limits<cost_t>::max()) {}

	void add_edge(int from, int to, flow_t cap, cost_t cost)
	{
		graph[from].emplace_back((edge){to, cap, cost, (int)graph[to].size(), false});
		graph[to].emplace_back((edge){from, 0, -cost, (int)graph[from].size() - 1, true});
	}

	cost_t min_cost_flow(int s, int t, flow_t f)
	{
		int V = (int)graph.size();
		cost_t ret = 0;
		using Pi = pair<cost_t, int>;
		priority_queue<Pi, vector<Pi>, greater<Pi>> que;
		potential.assign(V, INF);
		potential[s] = 0;
		while(1)
		{
			bool update = false;
			for (int i = 0; i < V;i++)
			{
				if(potential[i] != INF)
				{
					for (int j = 0; j < graph[i].size();j++)
					{
						edge &e = graph[i][j];
						cost_t nextCost = potential[i] + e.cost;
						if(e.cap > 0 && potential[e.to] > nextCost)
						{
							potential[e.to] = nextCost;
							update = true;
						}
					}
				}
			}
			if(!update)
				break;
		}
		preve.assign(V, -1);
		prevv.assign(V, -1);

		while (f > 0)
		{
			min_cost.assign(V, INF);
			que.emplace(0, s);
			min_cost[s] = 0;
			while (!que.empty())
			{
				Pi p = que.top();
				que.pop();
				if (min_cost[p.second] < p.first)
					continue;
				for (int i = 0; i < graph[p.second].size(); i++)
				{
					edge &e = graph[p.second][i];
					cost_t nextCost = min_cost[p.second] + e.cost + potential[p.second] - potential[e.to];
					if (e.cap > 0 && min_cost[e.to] > nextCost)
					{
						min_cost[e.to] = nextCost;
						prevv[e.to] = p.second, preve[e.to] = i;
						que.emplace(min_cost[e.to], e.to);
					}
				}
			}
			if (min_cost[t] == INF)
				return -1;
			for (int v = 0; v < V; v++)
				potential[v] += min_cost[v];
			flow_t addflow = f;
			for (int v = t; v != s; v = prevv[v])
			{
				addflow = min(addflow, graph[prevv[v]][preve[v]].cap);
			}
			f -= addflow;
			ret += addflow * potential[t];
			for (int v = t; v != s; v = prevv[v])
			{
				edge &e = graph[prevv[v]][preve[v]];
				e.cap -= addflow;
				graph[v][e.rev].cap += addflow;
			}
		}
		return ret;
	}

	void output()
	{
		for (int i = 0; i < graph.size(); i++)
		{
			for (auto &e : graph[i])
			{
				if (e.isrev)
					continue;
				auto &rev_e = graph[e.to][e.rev];
				cout << i << "->" << e.to << " (flow: " << rev_e.cap << "/" << rev_e.cap + e.cap << ")" << endl;
			}
		}
	}
};

int main()
{
	ll n, a[222222], b[222222];
	cin >> n;
	rep(i, n) cin >> a[i];
	rep(i, n) cin >> b[i];
	vector<ll> v1, v2;
	rep(i, n) if (a[i] > 0) v1.pb(a[i]);
	bool flag = false;
	rep(i, n * 2){
		if(!flag){
			if(b[i]==v1[0]){
				flag = true;
				v2.pb(b[i]);
			}
		}
		else{
			if(b[i%n]==v1[0])
				break;
			else if(b[i%n] > 0)
				v2.pb(b[i%n]);
		}
	}
	rep(i, v1.size()) if (v1[i] != v2[i]) flag = false;
	if(flag)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}