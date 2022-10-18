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
#define ll long long
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
#define N 105
struct Edge
{
	int v,w,cap,nxt;
};
Edge edge[N*40];
int fir[N],ss=1;
void add(int u,int v,int w,int x)
{
	// printf("%d %d %d %d\n",u,v,w,x);
	edge[++ss]=(Edge){v,x,w,fir[u]}; fir[u]=ss;
	edge[++ss]=(Edge){u,-x,0,fir[v]}; fir[v]=ss;
}
int n,m,dgr[N];
int s=101,t=102;
int dis[N],fr[N],fe[N],vis[N];
int spfa()
{
	memset(dis,0x3f,sizeof(dis));
	dis[s]=0; queue<int> q; q.push(s);
	while(!q.empty())
	{
		int u=q.front(); q.pop(); vis[u]=0;
		for(int i=fir[u];i!=0;i=edge[i].nxt)
		{
			if(edge[i].cap==0) continue;
			int v=edge[i].v;
			// printf("-- %d %d\n",u,v);
			if(dis[v]>dis[u]+edge[i].w)
			{
				dis[v]=dis[u]+edge[i].w;
				fe[v]=i,fr[v]=u;
				if(!vis[v]) q.push(v),vis[v]=1;
			}
		}
	}
	// printf("%d\n",dis[t]);
	if(dis[t]==inf) return -1;
	int go=inf,tmp=t;
	while(tmp!=s)
	{
		go=min(go,edge[fe[tmp]].cap);
		tmp=fr[tmp];
	}
	int cos=0; tmp=t;
	while(tmp!=s)
	{
		int i=fe[tmp];
		edge[i].cap-=go,edge[i^1].cap+=go;
		cos+=edge[i].w*go;
		tmp=fr[tmp];
	}
	if(!go) return -1;
	return cos;
}
int dinic()
{
	int ans=0,r;
	while((r=spfa())!=-1) ans+=r;
	return ans;
}
signed main()
{
	cin>>n>>m;
	int ans=0;
	for(int i=1;i<=m;i++)
	{
		int u=read(),v=read(),c=read(),f=read();
		dgr[u]-=f,dgr[v]+=f;
		if(c>=f)
		{
			add(v,u,f,1);
			add(u,v,c-f,1);
			add(u,v,inf,2);
		}
		else
		{
			ans+=f-c;
			add(v,u,f-c,0);
			add(v,u,c,1);
			add(u,v,inf,2);
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(dgr[i]<0) add(i,t,-dgr[i],0);
		else add(s,i,dgr[i],0);
	}
	add(n,1,inf,0);
	cout<<ans+dinic()<<endl;
	return 0;
}