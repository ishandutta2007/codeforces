#include <iostream>
#include <cstdio>
#include <vector>
#define maxn 1005
using namespace std;
int T, n, m, u, v;
long long a[maxn], b[maxn], tmp;
vector<int> G[maxn];
int vis[maxn], fa[maxn], f[maxn], t[maxn];
int type, str1, str2; 
void dfs(int x, int last, long long now)
{
	f[x] = now;
//	printf("%d %d %d\n", x, last, now);
	fa[x] = last;
	t[x] = 1;
	for (register int i = 0; i < G[x].size(); i++)
	{
		int V = G[x][i];
//		printf("!%d %d %d\n", V, x, now); 
		if(V == last) continue;
		if(vis[V])
		{
			type = 1, str1 = x;
			return;
		}
		if(now <= a[V]) continue;
		if(!t[V]) 
		{
			 dfs(V, x, now + b[V]);
		}
		else if(now + b[V] >= f[V])
		{
			type = 2, str1 = x, str2 = V;
			return;
		}
		if(type) return;
	}
}
int work()
{
	for (int i = 1; i <= n; i++) t[i] = 0;
	type = str1 = str2 = 0;
	for (int i = 1; i <= n; i++)
	{
		if(!vis[i]) continue;
		for (int j = 0; j < G[i].size(); j++)
		{
			int V = G[i][j];
			if(vis[V] || tmp <= a[V]) continue;
			dfs(V, i, tmp + b[V]);
		}
		if(type) break;
	}
	if(!type) return 0;
	if(type == 1)
	{
		for (int p = str1; !vis[p]; p = fa[p])
		{
			vis[p] = 1;
			tmp += b[p];
		}
	}
	if(type == 2)
	{
		for (int p = str1; !vis[p]; p = fa[p])
		{
			vis[p] = 1;
			tmp += b[p];
		}
		for (int p = str2; !vis[p]; p = fa[p])
		{
			vis[p] = 1;
			tmp += b[p];
		}
	}
//	printf("%d %d %d %d\n", type, str1, str2, tmp);
	return 1;
}
void solve()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) G[i].clear();
	for (int i = 2; i <= n; i++) scanf("%lld", &a[i]);
	for (int i = 2; i <= n; i++) scanf("%lld", &b[i]);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d%d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	int l = 1, r = 1000000001, mid;
	while(l < r)
	{
		mid = (l + r) >> 1;
		for (int i = 1; i <= n; i++) vis[i] = 0;
		vis[1] = 1;
		tmp = mid;
//		printf("%d\n", mid);
		while(work());
		int flag = 1;
		for (int i = 1; i <= n; i++) flag &= vis[i];
		if(flag) r = mid;
		else l = mid + 1;
	}
	printf("%d\n", l);
}
int main()
{
//	freopen("data.in", "r", stdin);
//	freopen("data.out", "w", stdout);
	scanf("%d", &T);
	while(T--) solve();
	return 0;
}