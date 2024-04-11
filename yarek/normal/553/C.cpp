#include <cstdio>
#include <vector>
using namespace std;

vector<pair<int, int>> g[100001];
int col[100001];

bool dfs(int v, int color = 2)
{
    if(col[v]) return col[v] == color;
    col[v] = color;
    for(auto u: g[v])
	if(!dfs(u.first, color ^ u.second))
	    return false;
    return true;
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    while(m--)
    {
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	c = 1 - c;
	g[a].emplace_back(b, c);
	g[b].emplace_back(a, c);
    }
    int ans = 1;
    for(int i = 1; i <= n; i++)
	if(col[i] == 0)
	    if(dfs(i))
	    {
		if(i != 1)
		    ans = (ans + ans) % 1000000007;
	    }
	    else ans = 0;
    printf("%d\n", ans);
}