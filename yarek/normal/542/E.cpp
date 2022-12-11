#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

vector<int> g[1001];
bool vis[1001];
int col[1001];
vector<int> compound;

bool dfs(int v, int color)
{
    if(col[v]) return color == col[v];
    col[v] = color;
    compound.push_back(v);
    for(auto u: g[v])
	if(!dfs(u, 3 - color)) return false;
    return true;
}

int longestPath(int start)
{
    queue<pair<int, int>> q;
    for(int i = 0; i <= 1000; i++)
	vis[i] = false;
    q.push(make_pair(start, 0));
    vis[start] = true;
    int ans = 0;
    while(!q.empty())
    {
	int v = q.front().first, d = q.front().second;
	q.pop();
	ans = max(ans, d);
	for(auto u: g[v])
	    if(!vis[u])
	    {
		vis[u] = true;
		q.push(make_pair(u, d + 1));
	    }
    }
    return ans;
}

int main()
{
    int n, m, a, b, ans = 0;
    scanf("%d %d", &n, &m);
    while(m--)
    {
	scanf("%d %d", &a, &b);
	g[a].push_back(b);
	g[b].push_back(a);
    }
    for(int i = 1; i <= n; i++)
	if(col[i] == 0)
	    if(!dfs(i, 1))
	    {
		puts("-1");
		return 0;
	    }
	    else
	    {
		int best = 0;
		for(auto v: compound)
		    best = max(best, longestPath(v));
		compound.clear();
		ans += best;
	    }
    printf("%d\n", ans);
}