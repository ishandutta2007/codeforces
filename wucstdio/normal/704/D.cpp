#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#include<map>
#define ll long long
using namespace std;
const int INF=2147483647;
struct Edge
{
	int to;
	int nxt;
	int flow;
}e[1000005];
struct Point
{
	int x,y;
}a[100005];
int n,m,s,t,edgenum=1,head[200105],cur[200105],from[200105],f[200105],dep[200105],p1[100005],p2[100005],tot1,tot2;
int L1[100005],L2[100005],d1[100005],d2[100005];
ll r,b,dis[200105],ans;
map<int,int>mp1,mp2;
queue<int>q;
void add(int u,int v,int f)
{
	e[++edgenum].flow=f;
	e[edgenum].to=v;
	e[edgenum].nxt=head[u];
	head[u]=edgenum;
}
bool bfs()
{
	while(!q.empty())q.pop();
	memset(dep,0,sizeof(dep));
	dep[s]=1;
	q.push(s);
	while(!q.empty())
	{
		int node=q.front();
		q.pop();
		for(int hd=head[node];hd;hd=e[hd].nxt)
		{
			int to=e[hd].to;
			if(e[hd].flow&&dep[to]==0)
			{
				dep[to]=dep[node]+1;
				q.push(to);
			}
		}
	}
	return dep[t];
}
int dfs(int node,int nowf)
{
	if(node==t)return nowf;
	for(int&hd=cur[node];hd;hd=e[hd].nxt)
	{
		int to=e[hd].to;
		if(dep[to]==dep[node]+1&&e[hd].flow)
		{
			int d=dfs(to,min(nowf,e[hd].flow));
			if(d>0)
			{
				e[hd].flow-=d;
				e[hd^1].flow+=d;
				return d;
			}
		}
	}
	return 0;
}
int Dinic()
{
	int ans=0,d;
	while(bfs())
	{
		for(int i=1;i<=t;i++)cur[i]=head[i];
		while((d=dfs(s,INF)))
		  ans+=d;
	}
	return ans;
}
int main()
{
	scanf("%d%d",&n,&m);
	scanf("%lld%lld",&r,&b);
	bool flag=0;
	if(r>b)
	{
		swap(r,b);
		flag=1;
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&a[i].x,&a[i].y);
		if(!mp1[a[i].x])mp1[a[i].x]=++tot1;
		if(!mp2[a[i].y])mp2[a[i].y]=++tot2;
	}
	for(int i=1;i<=n;i++)
	{
		int u=mp1[a[i].x],v=mp2[a[i].y];
		add(u,tot1+v,1);
		add(tot1+v,u,0);
		d1[u]++,d2[v]++;
	}
	for(int i=1;i<=m;i++)
	{
		int t,l,d;
		scanf("%d%d%d",&t,&l,&d);
		if(t==1)
		{
			l=mp1[l];
			if(l)L1[l]=max(L1[l],(d1[l]-d+1)>>1);
		}
		else
		{
			l=mp2[l];
			if(l)L2[l]=max(L2[l],(d2[l]-d+1)>>1);
		}
	}
	int tot=tot1+tot2;
	int ss=++tot,tt=++tot;
	s=++tot;
	t=++tot;
	int s1=0,s2=0;
	for(int i=1;i<=tot1;i++)
	{
		int R=d1[i]-L1[i];
		if(R<L1[i])
		{
			printf("-1\n");
			return 0;
		}
		if(R-L1[i])
		{
			add(ss,i,R-L1[i]);
			add(i,ss,0);
		}
		if(L1[i])
		{
			add(s,i,L1[i]);
			add(i,s,0);
		}
		s1+=L1[i];
	}
	for(int i=1;i<=tot2;i++)
	{
		int R=d2[i]-L2[i];
		if(R<L2[i])
		{
			printf("-1\n");
			return 0;
		}
		if(R-L2[i])
		{
			add(i+tot1,tt,R-L2[i]);
			add(tt,i+tot1,0);
		}
		if(L2[i])
		{
			add(i+tot1,t,L2[i]);
			add(t,i+tot1,0);
		}
		s2+=L2[i];
	}
	add(s,tt,s2);
	add(tt,s,0);
	add(ss,t,s1);
	add(t,ss,0);
	add(tt,ss,INF);
	add(ss,tt,0);
//	for(int i=1;i<=t;i++)
//	{
//		printf("%d:",i);
//		for(int hd=head[i];hd;hd=e[hd].nxt)
//		{
//			if(e[hd].flow)
//			  printf("(%d %d %lld) ",e[hd].to,e[hd].flow,e[hd].cost);
//		}
//		printf("\n");
//	}
	Dinic();
	s=ss,t=tt;
	Dinic();
	s+=2,t+=2;
	for(int hd=head[s];hd;hd=e[hd].nxt)
	{
		if(e[hd].flow)
		{
			printf("-1\n");
			return 0;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(e[i*2].flow==1)ans+=b;
		else ans+=r;
	}
	printf("%lld\n",ans);
	for(int i=1;i<=n;i++)
	{
		if(e[i*2].flow==1)putchar(flag?'r':'b');
		else putchar(flag?'b':'r');
	}
	putchar('\n');
	return 0;
}