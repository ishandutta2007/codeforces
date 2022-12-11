#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
int n;
vector<int> g[maxn];
int c[maxn],num[maxn];
int size[maxn],pure[maxn];
void dfs1(int u,int f)
{
	size[u]=1;pure[u]=1;
	for(int i=0;i<g[u].size();++i)
	{
		int v=g[u][i];
		if(v==f)continue;
		dfs1(v,u);
		size[u]+=size[v];
		if(!pure[v])pure[u]=0;
		if(c[u]!=c[v])pure[u]=0;
	}
}
int cnt;
bool Ans[maxn];
void dfs2(int u,int f)
{
	bool yes=1;
	int t=num[c[f]];
	if(c[u]==c[f])t--;
	for(int i=0;i<g[u].size();++i)
	{
		int v=g[u][i];
		if(v==f)continue;
		dfs2(v,u);
		if(!pure[v])yes=0;
		if(c[v]==c[f])t-=size[v];
	}
	if((t==n-size[u])&&yes)Ans[u]=1,cnt++;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&c[i]);
		num[c[i]]++;
	}
	dfs1(1,1);
	dfs2(1,0);
	if(!cnt)puts("NO");
	else
	{
		puts("YES");
		for(int i=1;i<=n;++i)if(Ans[i])
		{
			printf("%d\n",i);
			break;
		}
	}
	return 0;
}