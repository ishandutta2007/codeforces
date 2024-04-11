#include <bits/stdc++.h>
using namespace std;

int n,m,x,y;
int du[200001],vis[200001],st[200001],st_cnt;

vector <int> Son[200001];

void dfs(int u)
{
	vis[u]=1; st[++st_cnt]=u;
	for (auto v : Son[u])
	{
		if (!vis[v]) dfs(v);
	}
}

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		Son[x].push_back(y);
		Son[y].push_back(x);
		du[x]++; du[y]++;
	}
	for (int i=1;i<=n;i++)
	{
		st_cnt=0;
		if (!vis[i]) 
		{
			dfs(i);
			for (int j=1;j<=st_cnt;j++)
				if (du[st[j]]!=st_cnt-1)
				{
					printf("NO\n");
					return 0;
				}
		}
	}
	printf("YES\n");
	return 0;
}