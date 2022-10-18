#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define fir first
#define sec second
#define mod 998244353
#define int long long
#define inf ((int)1e18)
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
int mul(int x,int y){return 1LL*x*y%mod;}
#define N 20005
int dis1[N],dis2[N];
struct Edge
{
	int v,w,nxt;
};
Edge edge[N];
int fir[N],ss;
int s1,s2,t,n,p,q;
int u[N],v[N],l[N],r[N];
void add(int u,int v,int w)
{
	ss++;
	edge[ss].v=v,edge[ss].w=w;
	edge[ss].nxt=fir[u];fir[u]=ss;
}
struct Node
{
	int id,val;
	bool operator < (const Node &v) const
	{
		return val>v.val;
	}
};
void dij(int s,int* dis)
{
	for(int i=1;i<=n;i++) dis[i]=inf;
	dis[s]=0;
	priority_queue<Node> q;
	q.push((Node){s,0});
	while(!q.empty())
	{
		Node u=q.top(); q.pop();
		if(dis[u.id]!=u.val) continue;
		for(int i=fir[u.id];i!=0;i=edge[i].nxt)
		{
			int v=edge[i].v;
			if(dis[v]>dis[u.id]+edge[i].w)
			{
				dis[v]=dis[u.id]+edge[i].w;
				q.push((Node){v,dis[v]});
			}
		}
	}
}
signed main()
{
	cin>>n>>p>>q;
	cin>>s1>>s2>>t;
	for(int i=1;i<=p;i++)
	{
		int u=read(),v=read(),w=read();
		add(u,v,w);
	}
	for(int i=1;i<=q;i++)
	{
		u[i]=read(),v[i]=read(),l[i]=read(),r[i]=read();
		add(u[i],v[i],r[i]);
	}
	bool upd=1;
	while(upd)
	{
		upd=0;
		dij(s1,dis1),dij(s2,dis2);
		for(int i=1;i<=q;i++)
		{
			if(edge[i+p].w==l[i]) continue;
			if(dis1[u[i]]<=dis2[u[i]])
			{
				edge[i+p].w=l[i]; upd=1;
			}
		}
	}
	if(dis1[t]<dis2[t])
	{
		cout<<"WIN\n";
		for(int i=1;i<=q;i++) printf("%d ",edge[i+p].w);
	}
	else if(dis1[t]==dis2[t])
	{
		cout<<"DRAW\n";
		for(int i=1;i<=q;i++) printf("%d ",edge[i+p].w);
	}
	else cout<<"LOSE\n";
	return 0;
}