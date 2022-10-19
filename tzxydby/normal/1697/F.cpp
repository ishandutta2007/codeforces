#include<bits/stdc++.h>
using namespace std;
const int N=20005,K=12,M=500005;
int n,m,k,v0[N][K],v1[N][K],t,dfn[M],low[M],st[M],tp,in[M],s,b[M],ti,ans[N],vl[M];
vector<int>e[M];
void tarjan(int u)
{
	dfn[u]=low[u]=++ti;
	st[++tp]=u,in[u]=1;
	for(auto v:e[u])
	{
		if(!dfn[v])
		{
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}
		else if(in[v])
			low[u]=min(low[u],dfn[v]);
	}
	if(dfn[u]==low[u])
	{
		s++;
		int v;
		do
		{
			v=st[tp--];
			in[v]=0;
			b[v]=s;
		}while(v!=u);
	}
}
void sol()
{
	scanf("%d%d%d",&n,&m,&k);
	t=s=ti=tp=0;
	for(int i=1;i<=n;i++)
		for(int j=0;j<=k;j++)
			v0[i][j]=++t,v1[i][j]=++t;
	for(int i=1;i<=t;i++)
	{
		e[i].clear();
		dfn[i]=low[i]=st[i]=in[i]=b[i]=0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int x=0;x<=k;x++)
		{
			if(x+1<k) e[v1[i][x]].push_back(v1[i][x+1]);
			if(x) e[v0[i][x]].push_back(v0[i][x-1]);
		}
		e[v1[i][0]].push_back(v0[i][0]);
		e[v0[i][k]].push_back(v1[i][k]);
	}
	for(int i=1;i<=n;i++)
	{
		for(int x=0;x<=k;x++)
		{
			if(i>1) e[v1[i][x]].push_back(v1[i-1][x]);
			if(i<n) e[v0[i][x]].push_back(v0[i+1][x]);
		}
	}
	while(m--)
	{
		int op;
		scanf("%d",&op);
		if(op==1)
		{
			int i,v;
			scanf("%d%d",&i,&v);
			e[v1[i][v]].push_back(v1[i][v-1]);
			e[v0[i][v-1]].push_back(v0[i][v]);
		}
		if(op==2)
		{
			int i,j,v;
			scanf("%d%d%d",&i,&j,&v);
			for(int x=0;x<=k;x++)
				for(int y=0;y<=k;y++)
					if(x+y==v-1)
						e[v0[i][x]].push_back(v1[j][y]),e[v0[j][y]].push_back(v1[i][x]);
		}
		if(op==3)
		{
			int i,j,v;
			scanf("%d%d%d",&i,&j,&v);
			for(int x=0;x<=k;x++)
				for(int y=0;y<=k;y++)
					if(x+y==v-1)
						e[v1[i][x]].push_back(v0[j][y]),e[v1[j][y]].push_back(v0[i][x]);
		}
	}
	for(int i=1;i<=t;i++)
		if(!dfn[i])
			tarjan(i);
	for(int i=1;i<=n;i++)
	{
		ans[i]=0;
		for(int j=0;j<=k;j++)
		{
			int p0=b[v0[i][j]],p1=b[v1[i][j]];
			if(p0==p1)
			{
				puts("-1");
				return;
			}
			if(p0<p1)
				ans[i]=j+1;
		}
	}
	for(int i=1;i<=n;i++)
		printf("%d ",ans[i]);
	puts("");
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		sol();
	return 0;
}