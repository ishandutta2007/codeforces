#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
#include<cassert>
using namespace std;

typedef long long ll;

typedef unsigned long long ul;
typedef unsigned int ui;
const ll mod = 998244353;
const ll INF = mod * mod;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef pair<ll, ll> LP;
typedef vector<int> vec;
typedef vector<string> svec;
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-8;

#include<cstring>
struct edge { int to, cap, rev; };
vector<edge> G[100000];
bool used[100000];
void add_edge(int from, int to, int cap) {
	G[from].push_back(edge{ to, cap, (int)G[to].size() });
	G[to].push_back(edge{ from, 0, (int)G[from].size() - 1 });
}
int dfs(int v, int t, int f) {
	if (v == t)return f;
	used[v] = true;
	for (int i = 0; i < (int)G[v].size(); i++) {
		edge &e = G[v][i];
		if (!used[e.to] && e.cap > 0) {
			int d = dfs(e.to, t, min(f, e.cap));
			if (d > 0) {
				e.cap -= d;
				G[e.to][e.rev].cap += d;
				return d;
			}
		}
	}
	return 0;
}
int max_flow(int s, int t) {
	int flow = 0;
	for (;;) {
		memset(used, 0, sizeof(used));
		int f = dfs(s, t, mod);
		if (f == 0)return flow;
		flow += f;
	}
}

int dist[100][100];
void solve() {
	int n, m; cin >> n >> m;
	rep(i, n) {
		rep(j, n) {
			if (i == j)dist[i][j] = 0;
			else dist[i][j] = mod;
		}
	}
	rep(i, m) {
		int a, b; cin >> a >> b; a--; b--;
		dist[a][b] = dist[b][a] = 1;
	}
	rep(k,n) {
		rep(i, n) {
			rep(j, n) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	int nl, nr; ll k, h; cin >> nl >> nr >> k >> h;
	vector<int> a(nl), f(nl), xl(nl), xr(nr),b(nr);
	rep(i, nl) {
		cin >> xl[i] >> a[i] >> f[i]; xl[i]--;
	}
	rep(i, nr) {
		cin >> xr[i] >> b[i]; xr[i]--;
	}
	int s = nl + nr; int t = s + 1;
	rep(i, nl) {
		add_edge(s, i, 1);
	}
	rep(i, nr) {
		add_edge(i + nl, t, 1);
	}
	rep(i, nl) {
		rep(j, nr) {
			int d = dist[xl[i]][xr[j]];
			if (d <= f[i]&&a[i]>=b[j]) {
				add_edge(i, j + nl, 1);
			}
		}
	}
	int mf = max_flow(s, t);
	ll ans1 = (ll)mf * k; ll ans2 = (ll)nl*h;
	cout << min(ans1, ans2) << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	solve();
	//stop
	return 0;
}