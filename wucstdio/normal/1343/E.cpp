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
int t,n,m,a,b,c,edgenum,head[200005];
int dis[3][200005];
ll p[200005];
queue<int>q;
void add(int u,int v)
{
	e[++edgenum].to=v;
	e[edgenum].nxt=head[u];
	head[u]=edgenum;
}
void bfs(int st,int*dis)
{
	q.push(st);
	dis[st]=1;
	while(!q.empty())
	{
		int node=q.front();
		q.pop();
		for(int hd=head[node];hd;hd=e[hd].nxt)
		{
			int to=e[hd].to;
			if(!dis[to])
			{
				dis[to]=dis[node]+1;
				q.push(to);
			}
		}
	}
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d%d%d",&n,&m,&a,&b,&c);
		for(int i=1;i<=n;i++)head[i]=dis[0][i]=dis[1][i]=dis[2][i]=0;
		edgenum=0;
		for(int i=1;i<=m;i++)scanf("%lld",&p[i]);
		sort(p+1,p+m+1);
		for(int i=1;i<=m;i++)
		{
			p[i]+=p[i-1];
			int u,v;
			scanf("%d%d",&u,&v);
			add(u,v);
			add(v,u);
		}
		bfs(a,dis[0]);
		bfs(b,dis[1]);
		bfs(c,dis[2]);
		ll ans=1e18;
		for(int i=1;i<=n;i++)
		{
			if(dis[0][i]+dis[1][i]+dis[2][i]-3>m)continue;
			ans=min(ans,p[dis[1][i]-1]+p[dis[0][i]-1+dis[1][i]-1+dis[2][i]-1]);
		}
		printf("%lld\n",ans);
	}
	return 0;
}