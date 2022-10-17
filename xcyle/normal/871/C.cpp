#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define maxn 200005
#define ll long long
using namespace std;
const int mo = 1e9 + 7;
int n, x[maxn], y[maxn], tx[maxn], ty[maxn], vis[maxn];
vector<int> G[maxn];
int siz, flag;
int p[maxn];
void dfs(int x, int last)
{
	vis[x] = 1;
	siz++;
	for (int i = 0; i < G[x].size(); i++)
	{
		int V = G[x][i];
		if(V == last) continue;
		if(vis[V]) 
		{
			flag = 0;
			continue;
		}
		dfs(V, x);
	}
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d%d", &x[i], &y[i]);
		tx[i] = x[i], ty[i] = y[i];
	}
	sort(tx + 1, tx + n + 1), sort(ty + 1, ty + n + 1);
	int lx = unique(tx + 1, tx + n + 1) - tx - 1;
	int ly = unique(ty + 1, ty + n + 1) - ty - 1;
	for (int i = 1; i <= n; i++)
	{
		x[i] = lower_bound(tx + 1, tx + lx + 1, x[i]) - tx;
		y[i] = lower_bound(ty + 1, ty + ly + 1, y[i]) - ty;
		G[x[i]].push_back(n + y[i]);
		G[n + y[i]].push_back(x[i]);
	}
	p[0] = 1;
	for (int i = 1; i <= 2 * n; i++) p[i] = p[i - 1] * 2 % mo;
	int ans = 1;
	for (int i = 1; i <= 2 * n; i++)
	{
		if(!vis[i]) 
		{
			siz = 0, flag = 1;
			dfs(i, i);
			ans = (ll)ans * (p[siz] + mo - flag) % mo;
		}
	}
	printf("%d", ans);
	return 0;
}