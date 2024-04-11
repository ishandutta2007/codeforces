#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define dbg(...) fprintf(stderr, __VA_ARGS__)
#define dbgv(x) cerr << #x << " = " << x << endl
#define dbga(arr, len) {cerr << #arr << " = "; for (int _ = 0; _ < len; _++)\
cerr << arr[_] << " "; cerr << endl;}
#define dbgi(it) {cerr << #it << " = "; for (const auto& _ : it)\
cerr << _ << " "; cerr << endl;}
#else
#define dbg(...) (void)0
#define dbgv(x) (void)0
#define dbga(arr, len) (void)0
#define dbgi(it) (void)0
#endif

using ll = long long;
using dbl = long double;
using pii = pair<int, int>;

const int N = 300500;
const int INF = (int)1e9;

int n, m;
vector<int> go[N];
int qu[N];
int dist[N], par[N];

vector<int> solve1()
{
    fill(dist, dist + n, INF);
    dist[0] = 0;
    par[0] = -1;
    int ql = 0, qr = 0;
    qu[qr++] = 0;

    while (ql < qr)
    {
        int v = qu[ql++];
        for (int to : go[v])
        {
            if (dist[to] != INF)
                continue;
            dist[to] = dist[v] + 1;
            par[to] = v;
            qu[qr++] = to;
        }
    }

    if (dist[n - 1] == INF)
        return {};

    vector<int> path;
    for (int v = n - 1; v != -1; v = par[v])
        path.push_back(v);
    reverse(path.begin(), path.end());
    return path;
}

bool toone[N];
bool is_good[N];
bool gused[N];
set<pii> edges;
int gdist[N];
int gpar[N];

void bfs(int v)
{
	vector<int> q = {v};
	gpar[v] = -1;
	gdist[v] = 0;
	for (int i = 0; i < q.size(); ++i)
	{
		v = q[i];
		for(auto e : go[v])
			if (is_good[e] && gdist[e] == INF)
			{
				gdist[e] = gdist[v] + 1;
				gpar[e] = v;
				q.push_back(e);
			}
	}
}

vector<int> solve3(int v)
{
	vector<int> q;
	q.push_back(v);
	gused[v] = true;
	for (int i = 0; i < q.size(); ++i)
	{
		v = q[i];
		for(auto e : go[v])
			if (is_good[e] && !gused[e])
			{
				gused[e] = true;
				q.push_back(e);
			}
	}
	for(int i = 0; i < q.size(); ++i)
		for(int j = i + 1; j < q.size(); ++j)
			if (!edges.count({ q[i], q[j] }))
			{
				for (auto e : q)
					gdist[e] = INF;
				bfs(q[i]);
				for (auto e : q)
				{
					if (gdist[e] != 2)
						continue;
					return {0, q[i], gpar[e], e, q[i], n - 1};
				}
                throw;
			}
	return {};
}

vector<int> solve2()
{
	for (int i = 0; i < n; ++i)
		for (auto e : go[i])
			edges.emplace(i, e);
	for (auto v : go[0])
		toone[v] = true;
	for (int i = 1; i < n; ++i)
		for (auto e : go[i])
			if (toone[i] && !toone[e] && e != 0)
				return {0, i, e, 0, n - 1};
	vector<int> good = go[0];
	for (auto e : good)
		is_good[e] = true;
	for(int v : good)
		if (!gused[v])
		{
			auto vec = solve3(v);
			if (!vec.empty())
				return vec;
		}
	return {};
}

void solve()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        a--, b--;
        go[a].push_back(b);
        go[b].push_back(a);
    }

    auto way1 = solve1();
    auto way2 = solve2();
    if (!way2.empty() && (way1.empty() || way1.size() > way2.size()))
        way1 = way2;

    if (way1.empty())
    {
        puts("-1");
        return;
    }

    printf("%d\n", (int)way1.size() - 1);
    for (int v : way1)
        printf("%d ", v + 1);
    printf("\n");
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    solve();

    dbg("\n\ntime = %.3lf\n", (double)clock() / CLOCKS_PER_SEC);
}