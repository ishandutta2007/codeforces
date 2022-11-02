#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()

template<typename T> inline bool chkmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef long long LL;

const int oo = 0x3f3f3f3f;

const int maxn = 500100, maxm = 500100;

int n, K, m;

pair<int, pair<int, int> > ed[(maxm << 1) + 5];

int pa[maxn + 5];

int get(int x) { return pa[x] == x ? x : pa[x] = get(pa[x]); }

LL ans;

vector<pair<int, bool> > adj[maxn + 5];

bool w[maxn + 5];

int dep[maxn + 5];

int fa[maxn + 5];

void dfs(int x, int f = -1)
{
	fa[x] = f;
	for (auto y : adj[x]) if (y.x != f)
	{
		w[y.x] = y.y;
		dep[y.x] = dep[x] + 1;
		dfs(y.x, x);
	}
}

vector<pair<int, pair<int, int> > > not_in;

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d%d", &n, &K, &m);
	REP(i, 0, K)
	{
		int u, v;
		scanf("%d%d", &u, &v), --u, --v;
		ed[i] = mp(-1, mp(u, v));
	}
	REP(i, 0, m)
	{
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z), --x, --y;
		ed[K + i] = mp(z, mp(x, y));
	}
	sort(ed, ed + K + m);
	REP(i, 0, n) pa[i] = i;
	REP(i, 0, K + m)
	{
		int u = ed[i].y.x, v = ed[i].y.y;
		if (get(u) != get(v))
		{
			adj[u].pb(mp(v, ed[i].x == -1));
			adj[v].pb(mp(u, ed[i].x == -1));
			pa[get(u)] = get(v);
		}
		else not_in.pb(ed[i]);
	}
	dep[0] = 0;
	dfs(0);
	REP(i, 0, n) pa[i] = i;
	int res = K;
	ans = 0;
	for (auto e : not_in)
	{
		int u = get(e.y.x), v = get(e.y.y);
		while (u != v)
		{
			if (dep[u] > dep[v]) swap(u, v);
			if (w[v])
			{
				ans += e.x;
				--res;
			}
			pa[v] = fa[v];
			v = get(v);
		}
	}
	if (res) puts("-1");
	else
	{
		cout << ans << endl;
	}
	return 0;
}