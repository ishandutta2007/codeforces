#include<bits/stdc++.h>
using namespace std;
const int N=200005;
vector<int>e[N];
int dis[N],n,a,b,ans,mx,d[N],q[N],l,r;
void dfs(int u,int f)
{
	dis[u]=dis[f]+1;
	for(auto v:e[u])
		if(v!=f)
			dfs(v,u);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1,0);
	for(int i=1;i<=n;i++)
		if(dis[i]>dis[a])
			a=i;
	dis[a]=0;
	dfs(a,0);
	for(int i=1;i<=n;i++)
		if(dis[i]>dis[b])
			b=i;
	ans=dis[b];
	int x=b;
	for(int i=1;i<=n;i++)
		d[i]=-1;
	while(1)
	{
		d[x]=0;
		q[r++]=x;
		if(x==a)
			break;
		mx=x;
		for(auto v:e[x])
		{
			if(dis[v]+1==dis[x])
			{
				x=v;
				break;
			}
		}
	}
	while(l<r)
	{
		int k=q[l++];
		if(d[k]>d[mx])
			mx=k;
		for(auto v:e[k])
		{
			if(d[v]==-1)
			{
				d[v]=d[k]+1;
				q[r++]=v;
			}
		}
	}
	printf("%d\n",ans+d[mx]-1);
	printf("%d %d %d\n",a,b,mx);
	return 0;
}