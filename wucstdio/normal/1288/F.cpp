#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
const int INF=2147483647;
struct Edge
{
	int to;
	int nxt;
	int flow;
	int cost;
}e[10005];
int n1,n2,m,r,b,s,t,ss,tt,edgenum=1,head[505],dis[505],a[505],pre[505],d[505];
char s1[505],s2[505];
bool flag[1005];
queue<int>q;
void add(int u,int v,int f,int c)
{
	e[++edgenum].cost=c;
	e[edgenum].flow=f;
	e[edgenum].to=v;
	e[edgenum].nxt=head[u];
	head[u]=edgenum;
}
bool SPFA()
{
	while(!q.empty()) q.pop();
	for(int i=1;i<=t;i++)dis[i]=INF,a[i]=0,flag[i]=0;
	q.push(s);
	dis[s]=0;
	a[s]=INF;
	flag[s]=1;
	while(!q.empty())
	{
		int node=q.front();
		q.pop();
		flag[node]=0;
		for(int hd=head[node];hd;hd=e[hd].nxt)
		{
			if(e[hd].flow==0)continue;
			int to=e[hd].to;
			if(dis[to]>dis[node]+e[hd].cost)
			{
				dis[to]=dis[node]+e[hd].cost;
				a[to]=min(a[node],e[hd].flow);
				pre[to]=hd;
				if(!flag[to])
				{
					q.push(to);
					flag[to]=1;
				}
			}
		}
	}
	return dis[t]<INF;
}
int EK1()
{
	int ans=0;
	while(SPFA())
	{
		ans+=dis[t]*a[t];
		int x=t;
		while(x!=s)
		{
			int hd=pre[x];
			e[hd].flow-=a[t];
			e[hd^1].flow+=a[t];
			x=e[hd^1].to;
		}
	}
	return ans;
}
int EK2()
{
	int ans=0;
	while(SPFA())
	{
		if(dis[t]>=0)break;
		ans+=dis[t]*a[t];
		int x=t;
		while(x!=s)
		{
			int hd=pre[x];
			e[hd].flow-=a[t];
			e[hd^1].flow+=a[t];
			x=e[hd^1].to;
		}
	}
	return ans;
}
int main()
{
	scanf("%d%d%d%d%d",&n1,&n2,&m,&r,&b);
	ss=n1+n2+1;
	tt=ss+1;
	s=tt+1;
	t=s+1;
	scanf("%s%s",s1+1,s2+1);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		d[u]++,d[v+n1]++;
		add(u,v+n1,1,-r);
		add(v+n1,u,0,r);
		add(u,v+n1,1,b);
		add(v+n1,u,0,-b);
	}
	for(int i=1;i<=n1;i++)
	{
		if(s1[i]=='U')
		{
			add(ss,i,2*d[i],0);
			add(i,ss,0,0);
		}
		if(s1[i]=='R')
		{
			add(ss,i,d[i]-1,0);
			add(i,ss,0,0);
		}
		if(s1[i]=='B')
		{
			add(ss,i,d[i]-1,0);
			add(i,ss,0,0);
			add(s,i,d[i]+1,0);
			add(i,s,0,0);
			add(ss,t,d[i]+1,0);
			add(t,ss,0,0);
		}
	}
	for(int i=1;i<=n2;i++)
	{
		if(s2[i]=='U')
		{
			add(i+n1,tt,2*d[i+n1],0);
			add(tt,i+n1,0,0);
		}
		if(s2[i]=='R')
		{
			add(i+n1,tt,d[i+n1]-1,0);
			add(tt,i+n1,0,0);
		}
		if(s2[i]=='B')
		{
			add(i+n1,tt,d[i+n1]-1,0);
			add(tt,i+n1,0,0);
			add(s,tt,d[i+n1]+1,0);
			add(tt,s,0,0);
			add(i+n1,t,d[i+n1]+1,0);
			add(t,i+n1,0,0);
		}
	}
	add(tt,ss,INF,0);
	add(ss,tt,0,0);
	int ans=r*m;
	for(int i=2;i<edgenum;i+=2)
	{
		if(e[i].cost<0&&e[i].flow)
		{
			add(s,e[i].to,e[i].flow,0);
			add(e[i].to,s,0,0);
			add(e[i^1].to,t,e[i].flow,0);
			add(t,e[i^1].to,0,0);
			ans+=e[i].cost*e[i].flow;
			e[i^1].flow=e[i].flow,e[i].flow=0;
		}
	}
	ans+=EK1();
	for(int hd=head[s];hd;hd=e[hd].nxt)
	{
		if(e[hd].flow)
		{
			printf("-1\n");
			return 0;
		}
	}
	for(int hd=head[s];hd;hd=e[hd].nxt)
	{
		e[hd].flow=e[hd^1].flow=0;
	}
	for(int hd=head[t];hd;hd=e[hd].nxt)
	{
		e[hd].flow=e[hd^1].flow=0;
	}
	ans+=EK2();
	printf("%d\n",ans);
	for(int i=1;i<=m;i++)
	{
		if(e[4*i-2].flow==1)putchar('R');
		else if(e[4*i].flow==1)putchar('U');
		else putchar('B');
	}
	putchar('\n');
	return 0;
	return 0;
}