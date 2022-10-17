#pragma GCC optimize("Ofast","-funroll-loops")
#pragma GCC target("sse4.1","sse4.2","ssse3","sse3","sse2","sse","avx2","avx","popcnt","tune=native")
#include <iostream>
#include <cstdio>
#include <vector>
#define ll long long
#define maxn 200005
#define maxk 105
using namespace std;
const int mo = 1e9 + 7;
int n, k, x[2][maxk], z[maxk];
int vis[2][maxn];
vector<int> tmp[2];
int color[2][maxn]; 
int num_node, num_Edge;
int ans[maxn];
int isT[maxk];
vector<int> T[maxn], nonT;
int f[205][maxn][2], siz[maxn];
int g[maxk][2];
vector<int> e2[2][maxk]; 
int nonTdid[maxn];
int res[maxk];
int f2[(1 << 22)];
void init()
{
	for (int j = 1; j <= k; j++) isT[j] = 0;
	for (int j = 0; j < tmp[0].size(); j++) color[0][tmp[0][j]] = nonTdid[tmp[0][j]] = 0;
	for (int j = 0; j <= max(tmp[1].size(), tmp[0].size()); j++) e2[0][j].clear(), e2[1][j].clear();
	for (int j = 0; j < tmp[1].size(); j++) color[1][tmp[1][j]] = nonTdid[tmp[1][j]] = 0;
	tmp[0].clear(), tmp[1].clear();
	for (int j = 1; j <= k; j++) T[x[0][j]].clear(), T[n + x[1][j]].clear();
	nonT.clear();
}
void dfs(int u, int type)
{
	color[type][u] = 1;
	tmp[type].push_back(u);
	vis[type][u] = 1;
	for (register int i = 1; i <= k; i++)
	{
		if(x[type][i] == u && !vis[type ^ 1][x[type ^ 1][i]]) 
		{
			dfs(x[type ^ 1][i], type ^ 1);
			T[type * n + u].push_back(i);
			T[n - type * n + x[type ^ 1][i]].push_back(i);
			isT[i] = 1;
		}
	}
}
void work(int u, int fa)
{
//	printf("!!!!!!!!!!!%d %d\n", u, fa);
	for (int j = 0; j <= k; j++) f[j][u][0] = f[j][u][1] = 0;
	f[0][u][0] = 1;
	siz[u] = 1;
	for (int i = 0; i < T[u].size(); i++)
	{
		int flag = 0;
		if(u > n) flag = 1;
		int V = ((u - flag * n) ^ x[0][T[u][i]] ^ x[1][T[u][i]]);
		V += (1 - flag) * n;
		if(V == fa) continue;
		work(V, u);
		for (int j = 0; j <= k; j++)
		{
			g[j][0] = f[j][u][0];
			g[j][1] = f[j][u][1];
			f[j][u][0] = f[j][u][1] = 0;
		}
		for (int last = 0; last < siz[u]; last++)
		{
			for (register int now = 0; now < siz[V]; now++)
			{
				f[last + now][u][0] = (f[last + now][u][0] + (ll)g[last][0] * (f[now][V][0] + f[now][V][1]) % mo) % mo;
				f[last + now][u][1] = (f[last + now][u][1] + (ll)g[last][1] * f[now][V][0] % mo) % mo;
				f[last + now][u][1] = (f[last + now][u][1] + (ll)g[last][1] * f[now][V][1] % mo) % mo;
				f[last + now + 1][u][1] = (f[last + now + 1][u][1] + (ll)g[last][0] * f[now][V][0] % mo * z[T[u][i]] % mo) % mo;
			}
		}
		siz[u] += siz[V];
	}
	if(nonTdid[u])
	{
		for (int i = 0; i <= k; i++) 
		{
			f[i][u][1] = f[i][u][0];
			f[i][u][0] = 0;
		}
	}
//	for (int i = 0; i <= k; i++) printf("%d %d %d %d\n", u, i, f[i][u][0], f[i][u][1]);
}
void solve1(int u)
{
	for (int i = 0; i <= k; i++) res[i] = 0;
//	for (int i = 0; i < nonT.size(); i++) printf("%d %d\n", x[0][nonT[i]], x[1][nonT[i]]);
	for (int i = 0; i < (1 << nonT.size()); i++)
	{
//		printf("!\n");
		int cnt = 0, ttt = 1;
		for (int j = 0; j < nonT.size(); j++)
		{
			if((i >> j) & 1)
			{
				if(nonTdid[x[0][nonT[j]]]) ttt = 0;
				if(nonTdid[n + x[1][nonT[j]]]) ttt = 0;
				nonTdid[x[0][nonT[j]]] = 1;
				nonTdid[n + x[1][nonT[j]]] = 1;
				ttt = (ll)ttt * z[nonT[j]] % mo;
				cnt++;
//				printf("%d %d\n", x[0][nonT[j]], x[1][nonT[j]]);
			}
		}
		work(u, u);
//		printf("\n");
		for (int j = 0; j <= k - cnt; j++) res[cnt + j] = (res[cnt + j] + (ll)ttt * (f[j][u][1] + f[j][u][0]) % mo) % mo;
		for (int j = 0; j < nonT.size(); j++)
		{
			if((i >> j) & 1)
			{
				nonTdid[x[0][nonT[j]]] = 0;
				nonTdid[n + x[1][nonT[j]]] = 0;
			}
		}
	}
}
void solve2()
{
	int type;
	if(tmp[0].size() < tmp[1].size()) type = 1;
	else type = 0;
	for (int i = 1; i <= k; i++)
	{
		int l = -1;
		for (int j = 0; j < tmp[0].size(); j++)
		{
			if(tmp[0][j] == x[0][i]) l = j;
		}
		int r =  -1;
		for (int j = 0; j < tmp[1].size(); j++)
		{
			if(tmp[1][j] == x[1][i]) r = j;
		}
		if(l != -1 && r != -1)
		{
			if(type == 0)
			{
				e2[0][l].push_back(r);
				e2[1][l].push_back(i);
			}
			else
			{
				e2[0][r].push_back(l);
				e2[1][r].push_back(i);
			}
//			printf("%d %d\n", l, r);
		}
	}
	for (int j = (1 << tmp[type ^ 1].size()) - 1; j >= 0; j--) f2[j] = 0;
	f2[0] = 1;
	for (int i = 0; i < tmp[type].size(); i++)
	{
		for (int j = (1 << tmp[type ^ 1].size()) - 1; j >= 0; j--)
		{
			for (register int edge = 0; edge < e2[0][i].size(); edge++)
			{
				//printf("555");
				if(!((j >> e2[0][i][edge]) & 1))
				{
					f2[j | (1 << e2[0][i][edge])] = (f2[j | (1 << e2[0][i][edge])] + (ll)f2[j] * z[e2[1][i][edge]] % mo) % mo;
//					printf("!!!!!!!!");
				}
			}
		}
//		for (int j = 0; j < (1 << tmp[type ^ 1].size()); j++) printf("%d ", f2[j]);
//		printf("\n");
	}
	for (int i = 0; i <= k; i++) res[i] = 0;
	for (int i = 0; i < (1 << tmp[type ^ 1].size()); i++)
	{
		int cnt = 0;
		for (int j = 0; j < tmp[type ^ 1].size(); j++) cnt += ((i >> j) & 1);
		res[cnt] = (res[cnt] + f2[i]) % mo;	
	}
}
int fac[maxn];
int tmpans[maxk];
int needdo[maxn];
int main()
{
//	freopen("data.in", "r", stdin);
//	freopen("force.out", "w", stdout);
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= k; i++)
	{
		scanf("%d%d%d", &x[0][i], &x[1][i], &z[i]);
		z[i] = (z[i] + mo - 1) % mo;
		needdo[x[0][i]] = 1; 
	}
	ans[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		if(vis[0][i] || !needdo[i]) continue;
		init(); 
		dfs(i, 0);
		num_node = tmp[0].size() + tmp[1].size(), num_Edge = 0;
		for (int j = 1; j <= k; j++)
		{
			if(color[0][x[0][j]] && color[1][x[1][j]]) 
			{
				num_Edge++;
				if(!isT[j]) nonT.push_back(j);//printf(" 0 %d\n", j);
//				else printf(" 1 %d\n", j);
			}
		}
		if(num_node == 1) continue;
//		solve2();
		if(num_node >= num_Edge / 3 * 2 + 5) solve1(i);//,printf("1 ");
		else solve2();//,printf("2 ");
//printf("res: ");
//		for (int j = 0; j <= k; j++) printf("%d ", res[j]);
//		printf("\n");
		for (int j = 0; j <= k; j++)
		{
			tmpans[j] = ans[j];
			ans[j] = 0;
		}
		for (int now = 0; now <= num_Edge; now++)
		{
			if(!res[now]) continue;
			for (int last = 0; last + now <= k; last++)
			{
				ans[last + now] = (ans[last + now] + (ll)tmpans[last] * res[now] % mo) % mo;
			}
		}
	}
	fac[0] = 1;
	for (int i = 1; i <= n; i++) fac[i] = (ll)fac[i - 1] * i % mo;
	int res = 0;
	for (int i = 0; i <= min(n, k); i++)
	{
		res = (res + (ll)ans[i] * fac[n - i] % mo) % mo;
	}
	printf("%d\n", res);
	return 0;
}