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
	ll len;
}e[200005];
int n,m,s,t,edgenum,head[2005],sa1[2005],sa2[2005],rnk1[2005],rnk2[2005];
ll p[2005],dis[2005],val1[2005][2005],val2[2005][2005],f[2005][2005][2];
ll m1[2005][2005],m2[2005][2005];
int pos1[2005][2005],pos2[2005][2005];
bool flag[2005];
priority_queue<pair<ll,int>,vector<pair<ll,int> >,greater<pair<ll,int> > >q;
bool cmp(int a,int b)
{
	return dis[a]<dis[b];
}
void add(int u,int v,ll l)
{
	e[++edgenum].len=l;
	e[edgenum].to=v;
	e[edgenum].nxt=head[u];
	head[u]=edgenum;
}
void Dijkstra(int s)
{
	memset(dis,0x3f,sizeof(dis));
	while(!q.empty())q.pop();
	dis[s]=0;
	q.push(make_pair(dis[s],s));
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
				q.push(make_pair(dis[to],to));
			}
		}
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	scanf("%d%d",&s,&t);
	for(int i=1;i<=n;i++)scanf("%lld",&p[i]);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		ll l;
		scanf("%d%d%lld",&u,&v,&l);
		add(u,v,l);
		add(v,u,l);
	}
	Dijkstra(s);
	dis[0]=-1;
	for(int i=1;i<=n;i++)sa1[i]=i;
	sort(sa1+1,sa1+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		rnk1[sa1[i]]=i;
		if(dis[sa1[i]]==dis[sa1[i-1]])rnk1[sa1[i]]=rnk1[sa1[i-1]];
	}
	Dijkstra(t);
	dis[0]=-1;
	for(int i=1;i<=n;i++)sa2[i]=i;
	sort(sa2+1,sa2+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		rnk2[sa2[i]]=i;
		if(dis[sa2[i]]==dis[sa2[i-1]])rnk2[sa2[i]]=rnk2[sa2[i-1]];
	}
	for(int i=0;i<=n;i++)
	{
		flag[sa1[i]]=1;
		for(int j=1;j<=n;j++)val1[i][j]=val1[i][j-1]+(flag[sa2[j]]?0:p[sa2[j]]);
	}
	memset(flag,0,sizeof(flag));
	for(int i=0;i<=n;i++)
	{
		flag[sa2[i]]=1;
		for(int j=1;j<=n;j++)val2[i][j]=val2[i][j-1]+(flag[sa1[j]]?0:p[sa1[j]]);
	}
	for(int j=0;j<=n;j++)
	{
		for(int i=0;i<=n;i++)
		{
			pos1[i][j]=i==0?i:pos1[i-1][j];
			while(pos1[i][j]<=n&&(pos1[i][j]<=i||rnk2[sa1[pos1[i][j]]]<=j))pos1[i][j]++;
		}
	}
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=n;j++)
		{
			pos2[i][j]=j==0?j:pos2[i][j-1];
			while(pos2[i][j]<=n&&(pos2[i][j]<=j||rnk1[sa2[pos2[i][j]]]<=i))pos2[i][j]++;
		}
	}
	for(int i=0;i<=n+1;i++)
	{
		pos1[i][n+1]=pos1[n+1][i]=pos2[i][n+1]=pos2[n+1][i]=n+1;
		m1[i][n+1]=m1[n+1][i]=m2[i][n+1]=m2[n+1][i]=-1e18;
	}
	for(int i=n;i>=0;i--)
	{
		for(int j=n;j>=0;j--)
		{
			m1[i][j]=m1[i+1][j];
			for(int x=pos1[i][j];x<pos1[i+1][j];x++)
			{
				if(rnk1[sa1[x+1]]==rnk1[sa1[x]])continue;
				m1[i][j]=max(m1[i][j],-f[x][j][1]);
			}
			m2[i][j]=m2[i][j+1];
			for(int y=pos2[i][j];y<pos2[i][j+1];y++)
			{
				if(rnk2[sa2[y+1]]==rnk2[sa2[y]])continue;
				m2[i][j]=max(m2[i][j],-f[i][y][0]);
			}
			f[i][j][0]=m1[i][j];
			f[i][j][1]=m2[i][j];
			f[i][j][0]-=val2[j][i];
			f[i][j][1]-=val1[i][j];
			if(f[i][j][0]<-1e17)f[i][j][0]=0;
			if(f[i][j][1]<-1e17)f[i][j][1]=0;
//			printf("(%lld,%lld) ",f[i][j][0],f[i][j][1]);
			f[i][j][0]-=val1[i][j];
			f[i][j][1]-=val2[j][i];
		}
//		printf("\n");
	}
	if(f[0][0][0]>0)puts("Break a heart");
	if(f[0][0][0]==0)puts("Flowers");
	if(f[0][0][0]<0)puts("Cry");
	return 0;
}