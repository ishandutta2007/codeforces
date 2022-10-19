#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,m,q,t,k,dfn[N],low[N],st[N],tp,in[N],b[N];
long long d[N],gd[N],gs[N];
vector<pair<int,int>>e[N];
void dfs(int u)
{
	dfn[u]=low[u]=++t;
	st[++tp]=u,in[u]=1;
	for(auto i:e[u])
	{
		int v=i.first,w=i.second;
		if(!dfn[v])
		{
			d[v]=d[u]+w;
			dfs(v);
			low[u]=min(low[u],low[v]);
		}
		else if(in[v])
		{
			low[u]=min(low[u],dfn[v]);
			gd[u]=__gcd(gd[u],d[u]-d[v]+w);
		}
	}
	if(low[u]==dfn[u])
	{
		k++;
		int v;
		do
		{
			v=st[tp--];
			in[v]=0;
			b[v]=k;
			gs[k]=__gcd(gs[k],gd[v]);
		}while(v!=u);
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		e[u].emplace_back(v,w);
	}
	for(int i=1;i<=n;i++)
		if(!dfn[i])
			dfs(i);
	scanf("%d",&q);
	while(q--)
	{
		int u,s,t;
		scanf("%d%d%d",&u,&s,&t);
		if(!s)
			puts("YES");
		else if(!gs[b[u]])
			puts("NO");
		else
			puts(s%__gcd(gs[b[u]],(long long)t)?"NO":"YES");
	}
	return 0;
}