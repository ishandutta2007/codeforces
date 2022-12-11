#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1001;
vector<pair<int, int>> g[N];
const int M = 30001;
int x[M];
int y[M];
int w[M];
int forb = -1;
const int inf = 2e9 + 10;
bool vis[N];
int low[N];
int dist[N];
bool to_s_tab[M];
int n, s, t;

bool firstrun = true;
pair<int, int> dfs(int v, int d, int road)
{
    bool to_s = v == s;
    pair<int, int> ans(inf, -1);
    vis[v] = true;
    dist[v] = low[v] = d;
    for(auto u: g[v])
	if(u.second != road && u.second != forb)
	{
	    if(vis[u.first]) low[v] = min(low[v], dist[u.first]);
	    else
	    {
		auto p = dfs(u.first, d + 1, u.second);
		if(p.first != -1)
		{
		    to_s = true;
		    ans = p;
		}
		low[v] = min(low[v], low[u.first]);
	    }
	}
    if(firstrun && to_s) to_s_tab[road] = true;
    if(!to_s) return make_pair(-1, -1);
    if(low[v] == dist[v] && road != -1)
	ans = min(ans, make_pair(w[road], road));
    return ans;
}

pair<int, int> cost()
{
    for(int i = 1; i <= n; i++)
	vis[i] = low[i] = 0;
    auto p = dfs(t, 0, -1);
    if(p.first == -1) return make_pair(0, -1);
    return p;
}

int main()
{
    int m;
    scanf("%d %d %d %d", &n, &m, &s, &t);
    for(int i = 0; i < m; i++)
    {
	scanf("%d %d %d", x + i, y + i, w + i);
	g[x[i]].emplace_back(y[i], i);
	g[y[i]].emplace_back(x[i], i);
    }
    auto c = cost();
    pair<int, pair<int, int>> ans = make_pair(c.first, make_pair(c.second, -1));
    firstrun = false;
    for(forb = 0; forb < m; forb++)
    {
	if(!to_s_tab[forb]) continue;
	c = cost();
	if(c.first != inf) ans = min(ans, make_pair(c.first + w[forb], make_pair(forb, c.second)));
    }
    if(ans.first == inf)
    {
	puts("-1");
	return 0;
    }
    printf("%d\n%d\n", ans.first, (ans.second.first != -1) + (ans.second.second != -1));
    if(ans.second.first != -1) printf("%d ", ans.second.first + 1);
    if(ans.second.second != -1) printf("%d", ans.second.second + 1);
    puts("");
}