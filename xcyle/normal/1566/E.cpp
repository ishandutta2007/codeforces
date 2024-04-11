#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#define maxn 200005
using namespace std;
int T, n, a, b, d[maxn];
vector<int> G[maxn];
int p[maxn], f[maxn];
void dfs(int x, int fa)
{
	f[x] = fa;
	for (int i = 0; i < G[x].size(); i++)
	{
		int V = G[x][i];
		if(V == fa) continue;
		dfs(V, x);
	}
}
queue<int> q;
void solve()
{
	scanf("%d", &n);
	for (int i = 0; i <= n; i++) d[i] = p[i] = 0;
	for (int i = 0; i <= n; i++) G[i].clear();
	for (int i = 1; i < n; i++)
	{
		scanf("%d%d", &a, &b);
		G[a].push_back(b);
		G[b].push_back(a);
		d[a]++, d[b]++;
		p[a]++, p[b]++;
	}
	dfs(1, 0);
	d[1]++;
	p[1]++;
	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		if(d[i] == 1) 
		{
			p[f[i]]--;
			cnt++;
		}
	}
	for (int i = 1; i <= n; i++)
	{
//		printf("%d %d\n", d[i], p[i]);
		if(p[i] == 1 && d[i] != 1) 
		{
			q.push(i);
//		printf("%d ", i);
		}
	}
//	printf("\n");
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
//		printf("%d ", u);
		d[f[u]]--;
		if(u != 1 && d[f[u]] != 1) cnt--;
		p[f[u]]--;
		if(d[f[u]] == 1) p[f[f[u]]]--;
		if(p[f[f[u]]] == 1 && d[f[f[u]]] != 1) q.push(f[f[u]]);
		if(p[f[u]] == 1 && d[f[u]] != 1) q.push(f[u]);
	}
	printf("%d\n", cnt);
}
int main()
{
	scanf("%d", &T);
	while(T--) solve();
	return 0;
}