#include <iostream>
#include <cstdio>
#include <algorithm>
#define maxn 1005
using namespace std;
int n, l[maxn], r[maxn];
int ans = 1;
int t[maxn][maxn], cnt[maxn];
int vis[maxn];
int res[maxn];
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &l[i]);
	for (int i = 1; i <= n; i++) scanf("%d", &r[i]);
	for (int i = 1; i <= n; i++)
	{
		if(l[i] < 0 || l[i] > i - 1 || r[i] < 0 || r[i] > n - i) 
		{
			printf("NO\n");
			return 0;
		}
		t[l[i] + r[i]][++cnt[l[i] + r[i]]] = i;
	}
	for (int i = n; i >= 0; i--)
	{
		sort(t[i] + 1, t[i] + cnt[i] + 1);
		for (int j = 1; j <= cnt[i]; j++)
		{
			vis[t[i][j]] = 1;
			res[t[i][j]] = n - i;
		}
		for (int j = 1; j <= cnt[i]; j++)
		{
			int p = 0;
			for (int k = 1; k < t[i][j]; k++)
			{
				p += 1 - vis[k];
			}
			if(p != l[t[i][j]])
			{
				printf("NO\n");
				return 0;
			}
			p = 0;
			for (int k = n; k > t[i][j]; k--)
			{
				p += 1 - vis[k];
			}
			if(p != r[t[i][j]])
			{
				printf("NO\n");
				return 0;
			}
		}
	}
	if(!ans) printf("NO");
	else
	{
		printf("YES\n");
		for (int i = 1; i <= n; i++)
		{
			printf("%d ", res[i]);
		}
	}
	return 0;
}