#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#define ll long long
using namespace std;
struct Edge
{
	int to;
	int nxt;
}e[400005];
int n,m,edgenum,head[200005],pa[200005],d[200005],st;
ll w[200005],f[200005],ans;
queue<int>q;
bool flag[200005];
void add(int u,int v)
{
	e[++edgenum].to=v;
	e[edgenum].nxt=head[u];
	head[u]=edgenum;
}
void dfs(int node)
{
	f[node]=0;
	for(int hd=head[node];hd;hd=e[hd].nxt)
	{
		int to=e[hd].to;
		if(to==pa[node])continue;
		pa[to]=node;
		dfs(to);
		f[node]=max(f[node],f[to]);
	}
	f[node]+=w[node];
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&w[i]);
		ans+=w[i];
	}
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
		d[u]++;
		d[v]++;
	}
	scanf("%d",&st);
	if(m==n-1)
	{
		dfs(st);
		printf("%lld\n",f[st]);
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		if(d[i]==1)
		{
			q.push(i);
			flag[i]=1;
		}
	}
	while(!q.empty())
	{
		int node=q.front();
		q.pop();
		if(node!=st)
		{
			f[node]+=w[node];
			ans-=w[node];
		}
		for(int hd=head[node];hd;hd=e[hd].nxt)
		{
			int to=e[hd].to;
			if(flag[to])continue;
			d[to]--;
			if(st==node)st=to;
			f[to]=max(f[to],f[node]);
			if(d[to]==1)
			{
				flag[to]=1;
				q.push(to);
			}
		}
	}
	ll res=0;
	for(int i=1;i<=n;i++)
	  if(flag[i]==0)
	    res=max(res,f[i]);
	ans+=res;
	printf("%lld\n",ans);
	return 0;
}