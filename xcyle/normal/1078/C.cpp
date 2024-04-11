#include <iostream>
#include <cstdio>
#include <vector>
#define ll long long
#define maxn 300005
using namespace std;
const int mo = 998244353;
int n, x, y;
vector<int> G[maxn];
int f[maxn][2], g[maxn];
inline int pow(int x, int step)
{
	int res = 1;
	for(; step; step >>= 1)
	{
		if(step & 1) res = (ll)res * x % mo;
		x = (ll)x * x % mo;
	}
	return res;
}
void dfs(int x, int fa)
{
	int tmp = 1;
	g[x] = 1;
	for (int i = 0; i < G[x].size(); i++)
	{
		int V = G[x][i];
		if(V == fa) continue;
		dfs(V, x);
		g[x] = (ll)g[x] * (f[V][1] + g[V]) % mo;
		tmp = (ll)tmp * ((f[V][1] * 2 % mo + g[V]) % mo) % mo;
	}
	f[x][0] = tmp;
	for (int i = 0; i < G[x].size(); i++)
	{
		int V = G[x][i];
		if(V == fa) continue;
		f[x][1] = (f[x][1] + (ll)tmp * pow((f[V][1] * 2 % mo + g[V]) % mo, mo - 2) % mo * f[V][0] % mo) % mo;
	}
//	printf("%d %d %d %d\n", x, g[x], f[x][0], f[x][1]);
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i < n; i++)
	{
		scanf("%d%d", &x, &y);
		G[x].push_back(y), G[y].push_back(x);
	}
	dfs(1, 1);
	printf("%d", (f[1][1] + g[1]) % mo);
	return 0;
}