#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#define lson o<<1
#define rson o<<1|1
#define mid (l+r)/2
#define ll long long
using namespace std;
struct Edge
{
	int to;
	int nxt;
	ll len;
}e[1000005];
int n,m,qq,edgenum,head[200005],from1[200005],fromn[200005],top,p[200005];
int anc1[26][200005],ancn[26][200005],dep1[200005],depn[200005];
ll dis1[200005],disn[200005];
priority_queue<pair<ll,int>,vector<pair<ll,int> >,greater<pair<ll,int> > >q;
void add(int u,int v,ll l)
{
	e[++edgenum].len=l;
	e[edgenum].to=v;
	e[edgenum].nxt=head[u];
	head[u]=edgenum;
}
void Dijkstra(int s,ll*dis,int*from,int*dep)
{
	while(!q.empty())q.pop();
	dis[s]=0;
	dep[s]=1;
	q.push(make_pair(0,s));
	while(!q.empty())
	{
		ll d=q.top().first;
		int node=q.top().second;
		q.pop();
		if(dis[node]!=d)continue;
		for(int hd=head[node];hd;hd=e[hd].nxt)
		{
			int to=e[hd].to;
			if(dis[to]>dis[node]+e[hd].len)
			{
				dis[to]=dis[node]+e[hd].len;
				from[to]=node;
				dep[to]=dep[node]+1;
				q.push(make_pair(dis[to],to));
			}
		}
	}
}
int LCA1(int u,int v)
{
	if(dep1[u]<dep1[v])swap(u,v);
	for(int i=0;dep1[u]-dep1[v];i++)
	  if((1<<i)&(dep1[u]-dep1[v]))
		u=anc1[i][u];
	if(u==v)return u;
	for(int i=20;i>=0;i--)
	{
		if(anc1[i][u]!=anc1[i][v])
		{
			u=anc1[i][u];
			v=anc1[i][v];
		}
	}
	return anc1[0][u];
}
int LCAn(int u,int v)
{
	if(depn[u]<depn[v])swap(u,v);
	for(int i=0;depn[u]-depn[v];i++)
	  if((1<<i)&(depn[u]-depn[v]))
		u=ancn[i][u];
	if(u==v)return u;
	for(int i=20;i>=0;i--)
	{
		if(ancn[i][u]!=ancn[i][v])
		{
			u=ancn[i][u];
			v=ancn[i][v];
		}
	}
	return ancn[0][u];
}
ll minv[1000005];
ll query(int o,int l,int r,int p)
{
	if(l==r)return minv[o];
	ll ans=minv[o];
	if(p<=mid)ans=min(ans,query(lson,l,mid,p));
	else ans=min(ans,query(rson,mid+1,r,p));
	return ans;
}
void update(int o,int l,int r,int from,int to,ll v)
{
	if(l>=from&&r<=to)
	{
		minv[o]=min(minv[o],v);
		return;
	}
	if(from<=mid)update(lson,l,mid,from,to,v);
	if(to>mid)update(rson,mid+1,r,from,to,v);
}
int main()
{
	scanf("%d%d%d",&n,&m,&qq);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		ll l;
		scanf("%d%d%I64d",&u,&v,&l);
		add(u,v,l);
		add(v,u,l);
	}
	memset(dis1,0x3f,sizeof(dis1));
	memset(disn,0x3f,sizeof(disn));
	Dijkstra(1,dis1,from1,dep1);
	Dijkstra(n,disn,fromn,depn);
	for(int i=1;i<=n;i++)
	{
		anc1[0][i]=from1[i];
		ancn[0][i]=fromn[i];
	}
	for(int i=1;i<=20;i++)
	for(int j=1;j<=n;j++)
	{
		anc1[i][j]=anc1[i-1][anc1[i-1][j]];
		ancn[i][j]=ancn[i-1][ancn[i-1][j]];
	}
	int now=1;
	while(now!=n)
	{
		top++;
		p[now]=top;
		now=fromn[now];
	}
	memset(minv,0x3f,sizeof(minv));
	p[n]=top+1;
	for(int i=1;i<=edgenum;i+=2)
	{
		int u=e[i].to,v=e[i+1].to;
		ll d=min(dis1[u]+e[i].len+disn[v],dis1[v]+e[i].len+disn[u]);
		if((from1[u]==v||fromn[u]==v)&&d==dis1[n])continue;
		int xu=LCA1(u,n),yu=LCAn(u,1);
		int xv=LCA1(v,n),yv=LCAn(v,1);
		xu=p[xu],yu=p[from1[yu]];
		xv=p[xv],yv=p[from1[yv]];
		ll disuv=dis1[u]+e[i].len+disn[v];
		ll disvu=dis1[v]+e[i].len+disn[u];
		if(xu<=yv&&xu&&yv&&xu<=top&&yv<=top)update(1,1,top,xu,yv,disuv);
		if(xv<=yu&&xv&&yu&&xv<=top&&yu<=top)update(1,1,top,xv,yu,disvu);
	}
	while(qq--)
	{
		int x;
		ll y;
		scanf("%d%I64d",&x,&y);
		x=2*x-1;
		int u=e[x].to,v=e[x+1].to;
		ll d=min(dis1[u]+e[x].len+disn[v],dis1[v]+e[x].len+disn[u]);
		if((from1[u]==v||fromn[u]==v)&&p[u]&&p[v]&&d==dis1[n])
		{
			ll ans=min(dis1[u]+disn[v]+y,disn[u]+dis1[v]+y);
			ans=min(ans,query(1,1,top,min(p[u],p[v])));
			printf("%I64d\n",ans);
		}
		else
		{
			ll ans=min(dis1[u]+disn[v]+y,disn[u]+dis1[v]+y);
			ans=min(ans,dis1[n]);
			printf("%I64d\n",ans);
		}
	}
	return 0;
}