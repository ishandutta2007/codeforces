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
	int i, j, k;
	mint t;
	int n = a.size(), m = b[0].size(), l = a[0].size();
	Matrix c(n, vector<mint>(m));
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

template< typename flow_t >
struct Dinic {
  const flow_t INF;

  struct edge {
    int to;
    flow_t cap;
    int rev;
    bool isrev;
    int idx;
  };

  vector< vector< edge > > graph;
  vector< int > min_cost, iter;

  Dinic(int V) : INF(numeric_limits< flow_t >::max()), graph(V) {}

  void add_edge(int from, int to, flow_t cap, int idx = -1) {
    graph[from].emplace_back((edge) {to, cap, (int) graph[to].size(), false, idx});
    graph[to].emplace_back((edge) {from, 0, (int) graph[from].size() - 1, true, idx});
  }

  bool bfs(int s, int t) {
    min_cost.assign(graph.size(), -1);
    queue< int > que;
    min_cost[s] = 0;
    que.push(s);
    while(!que.empty() && min_cost[t] == -1) {
      int p = que.front();
      que.pop();
      for(auto &e : graph[p]) {
        if(e.cap > 0 && min_cost[e.to] == -1) {
          min_cost[e.to] = min_cost[p] + 1;
          que.push(e.to);
        }
      }
    }
    return min_cost[t] != -1;
  }

  flow_t dfs(int idx, const int t, flow_t flow) {
    if(idx == t) return flow;
    for(int &i = iter[idx]; i < graph[idx].size(); i++) {
      edge &e = graph[idx][i];
      if(e.cap > 0 && min_cost[idx] < min_cost[e.to]) {
        flow_t d = dfs(e.to, t, min(flow, e.cap));
        if(d > 0) {
          e.cap -= d;
          graph[e.to][e.rev].cap += d;
          return d;
        }
      }
    }
    return 0;
  }

  flow_t max_flow(int s, int t) {
    flow_t flow = 0;
    while(bfs(s, t)) {
      iter.assign(graph.size(), 0);
      flow_t f = 0;
      while((f = dfs(s, t, INF)) > 0) flow += f;
    }
    return flow;
  }

  vector<pair<pair<int,int>,int>> get_edges() {
      vector<pair<pair<int,int>,int>> E;
      for (int i = 0; i < graph.size(); i++)
      {
          for (auto &e : graph[i])
          {
              if (e.isrev)
                  continue;
              auto &rev_e = graph[e.to][e.rev];
              E.push_back(mp(mp(i, e.to), rev_e.cap));
          }
      }
      return E;
  }

  void output() {
    for(int i = 0; i < graph.size(); i++) {
      for(auto &e : graph[i]) {
        if(e.isrev) continue;
        auto &rev_e = graph[e.to][e.rev];
        cout << i << "->" << e.to << " (flow: " << rev_e.cap << "/" << e.cap + rev_e.cap << ")" << endl;
      }
    }
  }
};

int main()
{
	ll n;
	cin >> n;
	ll a[n];
	rep(i, n) cin >> a[i];
	ll li[n][n] = {};
	ll d[n] = {};
	rep(i,n){
		rep(j,n){
			ll s = a[i] + a[j];
			int flag = 1;
			for (ll p = 2; p * p <= s; p++){
				if(s%p==0){
					flag = 0;
					break;
				}
			}
			if(flag){
				li[i][j]++;
				d[i]++;
			}
		}
	}
	ll c[n];
	rep(i, n) c[i] = -1;
	int f = 0;
	rep(i, 2 * n){
		if(f){
			int f2 = 0;
			rep(j, n){
				rep(k, n){
					if(li[j][k]){
						if(c[j]!=-1&&c[k]==-1){
							c[k] = c[j] ^ 1;
							f2 = 1;
						}
						else if(c[k]!=-1&&c[j]==-1){
							c[j] = c[k] ^ 1;
							f2 = 1;
						}
					}
				}
			}
			if(!f2)
				f = 0;
		}
		else{
			rep(j,n){
				if(c[j]==-1){
					c[j] = 0;
					f = 1;
					break;
				}
			}
		}
	}
	Dinic<int> g(n+2);
	rep(i,n){
		for (int j = i + 1; j < n;j++){
			if(li[i][j]){
				if(c[i])
					g.add_edge(i, j, 1);
				else
					g.add_edge(j, i, 1);
			}
		}
		if(c[i])
			g.add_edge(n, i, 2);
		else
			g.add_edge(i, n + 1, 2);
	}
	if (g.max_flow(n,n+1) != n){
		cout << "Impossible" << endl;
		return 0;
	}
	auto res = g.get_edges();
	for(auto &e:res){
		if(!e.second){
			int u = e.first.first, v = e.first.second;
			li[u][v]--;
			li[v][u]--;
		}
	}
	vector<vector<ll>> ans;
	ll used[n] = {};
	rep(i,n){
		if(!used[i]){
			vector<ll> v;
			ll now = i;
			while (1){
				used[now]++;
				v.pb(now);
				rep(j, n){
					if (!used[j] && li[now][j]){
						now = j;
						break;
					}
				}
				if(used[now])
					break;
			}
			ans.pb(v);
		}
	}
	cout << ans.size() << endl;
	rep(i,ans.size()){
		cout << ans[i].size();
		rep(j, ans[i].size()) cout << " " << ans[i][j] + 1;
		cout << endl;
	}
}