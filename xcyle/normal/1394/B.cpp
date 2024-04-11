#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#define ll long long
#define lc(x) ((x) << 1)
#define rc(x) ((x) << 1 | 1)
#define maxn 200005
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
inline ll readll()
{
	ll x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int n, m, k, u, v, w;
int val[maxn][10], cnt[maxn];
vector<int> Gf[maxn], Gv[maxn];
int cntf[maxn];
int f[10][10][10][10];
int rk[maxn];
int c[10], ans;
void dfs(int x)
{
	if(x > k)
	{
		ans++;
		return;
	}
	for (register int i = 1; i <= x; i++)
	{
		c[x] = i;
		int flag = 1;
		for (int j = 1; j <= x; j++)
		{
			if(f[x][c[x]][j][c[j]] || f[j][c[j]][x][c[x]]) flag = 0;
		}
		if(!flag) continue;
		dfs(x + 1);
	}
}
int tmp[10][10]; 
int main()
{
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= m; i++)
	{
		u = read(), v = read(), w = read();
		val[u][++cnt[u]] = w;
		Gf[v].push_back(u);
		Gv[v].push_back(w);
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= k; j++) for (int c = 1; c <= k; c++) tmp[j][c] = 0;
		for (int j = 0; j < Gf[i].size(); j++)
		{
			int V = Gf[i][j];
			rk[j] = 1;
			for (register int k = 1; k <= cnt[V]; k++) rk[j] += (val[V][k] < Gv[i][j] ? 1 : 0);
			tmp[cnt[V]][rk[j]]++;
		}
		for (int l1 = 1; l1 <= k; l1++)
		{
			for (int r1 = 1; r1 <= l1; r1++)
			{
				if(!tmp[l1][r1]) continue;
				for (int l2 = 1; l2 <= k; l2++)
				{
					for (register int r2 = 1; r2 <= l2; r2++)
					{
						if(!tmp[l2][r2]) continue;
						if(l1 == l2 && r1 == r2 && tmp[l1][r1] == 1) continue;
						f[l1][r1][l2][r2] = 1;
					}
				}
			}
		}
//		for (int j = 1; j <= cntf[i]; j++)
//		{
//			for (register int k = j + 1; k <= cntf[i]; k++)
//			{
//				f[cnt[Gf[i][j]]][rk[j]][cnt[Gf[i][k]]][rk[k]] = 1;
//			}
//		}
	}
	dfs(1);
	printf("%d\n", ans);
	return 0;
}