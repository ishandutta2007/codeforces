#include <iostream>
#include <cstdio>
#define maxn 505
using namespace std;
const int mo = 998244353;
int t, n, a[1005][maxn], vis[1005];
int cnt[maxn];
int num[2];
int ans = 1;
int res[maxn], tot;
void dfs(int x, int dep)
{
	if(!dep) res[++tot] = x;
	num[dep]++;
	vis[x] = 1;
	for (int i = 1; i <= 2 * n; i++)
	{
		if(vis[i]) continue;
		for (int j = 1; j <= n; j++)
		{
			if(a[x][j] == a[i][j])
			{
				dfs(i, dep ^ 1);
				break;
			}
		}
	}
}
void solve()
{
	for (int i = 1; i <= 2 * n; i++)
	{
		if(vis[i]) continue;
		num[0] = num[1] = 0;
		dfs(i, 0);
		if(num[0] == num[1]) ans = ans * 2 % mo;
	}
}
int main()
{
	scanf("%d", &t);
	while(t--)
	{
		ans = 1;
		tot = 0;
		scanf("%d", &n);
		for (int i = 1; i <= 2 * n; i++)
		{
			vis[i] = 0;
			for (int j = 1; j <= n; j++)
			{
				scanf("%d", &a[i][j]);
			}
		}
		int flag = 1;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++) cnt[j] = 0;
			for (int j = 1; j <= 2 * n; j++) cnt[a[j][i]]++;
			for (int j = 1; j <= n; j++)
			{
				if(cnt[j] != 2) flag = 0;
			}
		}
		if(flag == 1)
		{
			solve();
			printf("%d\n", ans);
			for (int i = 1; i <= tot; i++) printf("%d ", res[i]);
			printf("\n");
		}
		else
		{
			while(1)
			{
				int type = 0;
				for (int i = 1; i <= 2 * n; i++)
				{
					if(!vis[i]) type = 1;
				}
				if(!type) break;
				type = 0;
				for (int i = 1; i <= n; i++)
				{
					for (int j = 1; j <= n; j++) cnt[j] = 0;
					for (int j = 1; j <= 2 * n; j++) 
					{
						if(vis[j]) continue; 
						cnt[a[j][i]]++;
					} 
					for (int j = 1; j <= 2 * n; j++)
					{
						if(vis[j]) continue;
						if(cnt[a[j][i]] == 1)
						{
							vis[j] = 1;
							res[++tot] = j;
							type = j;
							break;
						}
					}
					if(type) break;
				}
				if(!type)
				{
//					for (int i = 1; i <= 2 * n; i++) printf("%d ", vis[i]);
//					printf("\n");
					 solve();
					 break;
				}
				for (int i = 1; i <= 2 * n; i++)
				{
					if(vis[i] && i != type) continue;
					for (int j = 1; j <= n; j++)
					{
						if(a[i][j] == a[type][j]) vis[i] = 1;
					}
				}
			}
			printf("%d\n", ans);
//			printf("!");
			for (int i = 1; i <= tot; i++) printf("%d ", res[i]);
			printf("\n");
		}
	}
	return 0;
}