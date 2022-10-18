#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
#define fir first
#define sec second
#define mod 998244353
#define int long long
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
#define N 10005
struct Edge
{
	int v,w,nxt,cap;
};
Edge edge[N];
int fir[N],ss=1;
void add(int u,int v,int w,int c)
{
	edge[++ss]=(Edge){v,w,fir[u],c}; fir[u]=ss;
	edge[++ss]=(Edge){u,-w,fir[v],0}; fir[v]=ss;
}
int dis[N],vis[N],fr[N],fe[N],n,m,cost[N],cnt;
bool bfs()
{
	for(int i=1;i<=n;i++) dis[i]=INF;
	dis[1]=0; queue<int> q; q.push(1);
	while(!q.empty())
	{
		int u=q.front(); q.pop(); vis[u]=0;
		for(int i=fir[u];i!=0;i=edge[i].nxt)
		{
			if(!edge[i].cap) continue;
			int v=edge[i].v;
			if(dis[v]>dis[u]+edge[i].w)
			{
				dis[v]=dis[u]+edge[i].w,fr[v]=u,fe[v]=i;
				if(!vis[v]) vis[v]=1,q.push(v);
			}
		}
	}
	return dis[n]<INF;
}
void dinic()
{
	while(bfs())
	{
		cnt++; cost[cnt]=cost[cnt-1]+dis[n];
		int tmp=n;
		while(tmp!=1)
		{
			int e=fe[tmp]; tmp=fr[tmp];
			edge[e].cap--,edge[e^1].cap++;
		}
	}
}
signed main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int u=read(),v=read(),w=read();
		add(u,v,w,1);
	}
	dinic();
	int Q=read();
	while(Q--)
	{
		int x=read(); double ans=INF;
		for(int i=1;i<=cnt;i++) ans=min(ans,(double)(cost[i]+x)/i);
		printf("%.7lf\n",ans);
	}
	return 0;
}