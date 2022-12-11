#include<bits/stdc++.h>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
const int N=600+5;
const int M=181200+5;
int End[M],Last[N],Next[M],cap[M];
int e=1;
void add_edge(int x,int y,int c)
{
	End[++e]=y;
	Next[e]=Last[x];
	Last[x]=e;
	cap[e]=c;
	End[++e]=x;
	Next[e]=Last[y];
	Last[y]=e;
	cap[e]=0;
}
int dis[N],tot[N],Last1[N];
bool inq[N];
int n,s,t;
void bfs()
{
	for(int i=1;i<=n;i++) dis[i]=n;
	dis[t]=0;
	queue<int> q;
	q.push(t);
	inq[t]=true;
	while(q.size())
	{
		int x=q.front();
		q.pop();
		inq[x]=false;
		for(int i=Last[x];i;i=Next[i])
		{
			int y=End[i];
			if(dis[y]>dis[x]+1)
			{
				dis[y]=dis[x]+1;
				if(!inq[y])
				{
					q.push(y);
					inq[y]=true;
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		tot[dis[i]]++;
		Last1[i]=Last[i];
	}
}
typedef long long i64;
const int inf=1e9;
i64 dfs(int x,i64 flow)
{
	if(x==t) return flow;
	i64 flow_now=0;
	for(int &i=Last[x];i;i=Next[i])
	{
		int y=End[i];
		if(cap[i]>0&&dis[x]==dis[y]+1)
		{
			i64 f=dfs(y,min(flow-flow_now,cap[i]));
			flow_now+=f;
			cap[i]-=f;
			cap[i^1]+=f;
			if(flow==flow_now||dis[s]==n) return flow_now;
		}
	}
	if(!--tot[dis[x]]) dis[s]=n;
	tot[++dis[x]]++;
	Last[x]=Last1[x];
	return flow_now;
}
i64 sum;
void init()
{
	int N;
	scanf("%d",&N);
	n=(N<<1)+2;
	s=n-1,t=n;
	for(int i=1;i<=N;i++)
	{
		int t;
		scanf("%d",&t);
		while(t--)
		{
			int x;
			scanf("%d",&x);
			add_edge(i,x+N,inf);
		}
	}
	for(int i=1;i<=N;i++)
	{
		int p;
		scanf("%d",&p);
		add_edge(s,i,inf-p);
		sum+=inf-p;
	}
	for(int i=1;i<=N;i++) add_edge(i+N,t,inf);
}
void solve()
{
	i64 flow=0;
	bfs(); 
	while(dis[s]<n) flow+=dfs(s,1e18);
	printf("%lld",flow-sum);
}
int main()
{
	init();
	solve();
	return 0;
}