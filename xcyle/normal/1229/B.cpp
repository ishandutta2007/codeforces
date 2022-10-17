#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#define ll long long
#define maxn 100005
using namespace std;
const int mo = 1e9 + 7;
int n, x, y, dep[maxn];
vector<int> G[maxn];
int fa[maxn][20];
long long a[maxn], pa[maxn][20];
inline long long gcd(long long x, long long y)
{
	if(x < y) swap(x, y);
	return y == 0 ? x : gcd(y, x % y);
}
long long res[maxn];
void dfs(int x, int f)
{
	dep[x] = dep[f] + 1;
	fa[x][0] = f, pa[x][0] = a[x];
	for (register int i = 1; i < 20; i++)
	{
		fa[x][i] = fa[fa[x][i - 1]][i - 1];
		pa[x][i] = gcd(pa[x][i - 1], pa[fa[x][i - 1]][i - 1]);
	}
		int p = fa[x][0];
		ll now = a[x];
		if(a[x] == 0)
		{
			res[x] = res[fa[x][0]];
//		printf("%lld\n", res[x]);
		}
		else
		{
//		printf("!!! %d   ", i);
		while(1)
		{
			
			ll tmp = p;
			for (register int i = 19; i >= 0; i--)
			{
				if(p == 0) break;
				if(pa[p][i] % now == 0) p = fa[p][i];
			}
			res[x] = (res[x] + (ll)(dep[tmp] - dep[p] + 1) * now % mo) % mo;
			if(p == 0) break;
			now = gcd(now, pa[p][0]);
			p = fa[p][0];
//			printf("%d ", p);
		} 
//		printf("%lld\n", res[x]);
		}
	for (int i = 0; i < G[x].size(); i++)
	{
		int V = G[x][i];
		if(V == f) continue;
		dfs(V, x);
	}
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	for (int i = 1; i < n; i++)
	{
		scanf("%d%d", &x, &y);
		G[x].push_back(y), G[y].push_back(x);
	}
	dfs(1, 0);
	ll ans = 0;
	for (int i = 1; i <= n; i++) ans = (ans + res[i]) % mo;
	printf("%lld", ans);
	return 0;
}