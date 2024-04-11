#include<bits/stdc++.h>
#define ll long long
#define maxn 5005
using namespace std;
int n,m,s;
vector<int> e[maxn];
int to[maxn],vis[maxn];
int lnk[maxn][maxn];
void dfs(int u,int rt)
{
	vis[u]=1;lnk[rt][u]=1;to[rt]++;
	int siz=e[u].size();
	for(int i=0;i<siz;++i)
	{
		int v=e[u][i];
		if(vis[v])continue;
		dfs(v,rt);
	}
}
int main()
{
	scanf("%d%d%d",&n,&m,&s);
	for(int i=1;i<=m;++i)
	{
		int u,v;scanf("%d%d",&u,&v);
		e[u].push_back(v);
	}
	for(int i=1;i<=n;++i)
	{
		memset(vis,0,sizeof(vis));
		dfs(i,i);
	}
	memset(vis,0,sizeof(vis));
	int cnt=n;
	for(int i=1;i<=n;++i)if(lnk[s][i])
	{
		vis[i]=1;
		for(int j=1;j<=n;++j)if(lnk[j][i])lnk[j][i]=0,to[j]--;
		cnt--;
	}
	int ans=0;
	while(cnt)
	{
		int mx=0;
		for(int i=1;i<=n;++i)if(to[mx]<to[i])mx=i;
		for(int i=1;i<=n;++i)if(lnk[mx][i]&&(!vis[i]))
		{
			vis[i]=1;
			for(int j=1;j<=n;++j)if(lnk[j][i])lnk[j][i]=0,to[j]--;
			cnt--;
		}
		ans++;
	}
	printf("%d\n",ans);
	return 0;
}