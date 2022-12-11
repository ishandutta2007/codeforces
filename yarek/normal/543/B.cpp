#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int d[3001][3001];
vector<int> g[3001];
const int inf = 10000;

int main()
{
    int n, m, a, b, ans = inf;
    int s1, t1, l1, s2, t2, l2;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++)
    {
	scanf("%d %d", &a, &b);
	g[a].push_back(b);
	g[b].push_back(a);
    }
    scanf("%d %d %d %d %d %d", &s1, &t1, &l1, &s2, &t2, &l2);
    for(int i = 1; i <= n; i++)
    {
	for(int j = 1; j <= n; j++)
	    d[i][j] = inf;
	d[i][i] = 0;
	queue<int> q;
	q.push(i);
	while(!q.empty())
	{
	    int v = q.front();
	    q.pop();
	    for(int u: g[v])
		if(d[i][u] == inf)
		{
		    d[i][u] = d[i][v] + 1;
		    q.push(u);
		}
	}
    }
    if(d[s1][t1] > l1 || d[s2][t2] > l2)
    {
	puts("-1");
	return 0;
    }
    ans = d[s1][t1] + d[s2][t2];
    for(int i = 1; i <= n; i++)
	for(int j = 1; j <= n; j++)
	{
	    int d1 = d[i][j], d2 = min(d[s1][i] + d[j][t1], d[s1][j] + d[i][t1]),
		d3 = min(d[s2][i] + d[j][t2], d[s2][j] + d[i][t2]);
	    if(d1 + d2 <= l1 && d1 + d3 <= l2)
		ans = min(ans, d1 + d2 + d3);
	}
    printf("%d\n", m - ans);
}