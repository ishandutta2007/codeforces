#include <bits/stdc++.h>

using namespace std;

const int maxn = 200005;

int a[maxn], cha[maxn], vis[maxn];
int n, cnt;
vector <int> ke[maxn];

void nhap()
{
	scanf("%d", &n);
	cnt = 0;
	for(int i=1; i<=n; i++)
	{
		scanf("%d", &a[i]);
		cnt += (a[i] == 1);
	}
	for(int i=1; i<n; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		ke[u].push_back(v);
		ke[v].push_back(u);
	}
}

void dfs(int u)
{
	printf("%d ", u);
	a[u] = - a[u];
	for(int j=0; j<ke[u].size(); j++)
	{
		int v = ke[u][j];
		if (!vis[v])
		{
			cha[v] = u;
			vis[v] = 1;
			dfs(v);
			if (u != 1 || j != (int)(ke[u].size()) - 1)
			{
				printf("%d ", u);
				a[u] = - a[u];
			} else 
			{
				if (a[u] == -1)
				{
					printf("%d ", u);
					a[u] = - a[u];
				}
			}
		}
	}
	if (a[u] == -1)
	{
		printf("%d ", cha[u]);
		a[cha[u]] = - a[cha[u]];
		printf("%d ", u);
		a[u] = - a[u];
	}
}

int main()
{
	//freopen("test.inp", "r", stdin);
	nhap();
	if (cnt == n)
	{
		printf("1\n");
		return 0;
	}
	a[1] = -a[1];
	memset(vis,0,sizeof(vis));
	vis[1] = 1;
	dfs(1);
	return 0;
}