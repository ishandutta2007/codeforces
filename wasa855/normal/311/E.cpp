#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define fir first
#define sec second
#define mod 998244353
#define INF 0x3fffffff
#define ll long long
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
#define N 200005
int a[N],s,t;
struct Edge
{
	int v,nxt,cap;
};
Edge edge[N*2];
int fir[N],ss=1;
void add(int u,int v,int w)
{
	ss++;
	edge[ss].v=v,edge[ss].cap=w;
	edge[ss].nxt=fir[u],fir[u]=ss;
	ss++;
	edge[ss].v=u,edge[ss].cap=0;
	edge[ss].nxt=fir[v],fir[v]=ss;
}
int dep[N];
bool bfs(int u)
{
	for(int i=1;i<N;i++)  dep[i]=0;
	dep[u]=1;
	queue<int> q;
	q.push(u);
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(int i=fir[u];i!=0;i=edge[i].nxt)
		{
			if(edge[i].cap==0) continue;
			int v=edge[i].v;
			if(!dep[v])
			{
				dep[v]=dep[u]+1;
				q.push(v);
			}
		}
	}
	return dep[t];
}
int dfs(int u,int flow)
{
	if(u==t) return flow;
	if(!flow) return flow;
	int go=0;
	for(int i=fir[u];i!=0;i=edge[i].nxt)
	{
		if(edge[i].cap==0) continue;
		int v=edge[i].v;
		if(dep[v]!=dep[u]+1) continue;
		int R=dfs(v,min(flow,edge[i].cap));
		edge[i].cap-=R,edge[i^1].cap+=R;
		flow-=R,go+=R;
	}
	return go;
}
int dinic()
{
	int ans=0;
	while(bfs(s)) ans+=dfs(s,INF);
	return ans;
}
signed main()
{
	int n=read(),m=read(),g=read();
	s=n+m+1,t=n+m+2;
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=n;i++)
	{
		int w=read();
		if(a[i]) add(i,t,w);
		else add(s,i,w);
	}
	int sum=0;
	for(int i=1;i<=m;i++)
	{
		int o=read(),w=read(),k=read();
		sum+=w;
		if(o)
		{
			while(k--)
			{
				int u=read();
				add(u,n+i,INF);
			}
			int p=read();
			if(p) add(n+i,t,g+w);
			else add(n+i,t,w);
		}
		else
		{
			while(k--)
			{
				int u=read();
				add(n+i,u,INF);
			}
			int p=read();
			if(p) add(s,n+i,g+w);
			else add(s,n+i,w);
		}
	}
	cout<<sum-dinic()<<endl;
	return 0;
}