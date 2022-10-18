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
void print(vector<int> x){for(int i=0;i<(int)x.size();i++) printf("%lld%c",x[i]," \n"[i==(int)x.size()-1]);}
typedef pair<int,int> pii;
#define N 1005
int v[N],ans[N],vis[N],n,m;
vector<int> G[N]; // u <= v
struct Edge{int v,cap,nxt;};
Edge edge[N*512];
int fir[N],dep[N],cur[N],ss,s,t;
void add(int u,int v,int w)
{
	// printf("%d %d %d\n",u,v,w);
	edge[++ss]=(Edge){v,w,fir[u]}; fir[u]=ss;
	edge[++ss]=(Edge){u,0,fir[v]}; fir[v]=ss;
}
bool bfs(int siz)
{
	for(int i=0;i<siz;i++) dep[i]=0;
	dep[s]=1,dep[t]=0;
	queue<int> q; q.push(s);
	while(!q.empty())
	{
		int u=q.front(); q.pop();
		for(int i=fir[u];i!=0;i=edge[i].nxt)
		{
			if(!edge[i].cap) continue;
			int v=edge[i].v;
			if(!dep[v]) dep[v]=dep[u]+1,q.push(v);
		}
	}
	return dep[t];
}
int dfs(int u,int flow)
{
	if(u==t||!flow) return flow;
	int go=0;
	for(int &i=cur[u];i!=0;i=edge[i].nxt)
	{
		int v=edge[i].v;
		if(!edge[i].cap||dep[v]!=dep[u]+1) continue;
		int r=dfs(v,min(flow,edge[i].cap));
		go+=r,flow-=r;
		edge[i].cap-=r,edge[i^1].cap+=r;
		if(!flow) return go;
	}
	return go;
}
int dinic(int siz)
{
	int ans=0;
	while(bfs(siz))
	{
		for(int i=0;i<siz;i++) cur[i]=fir[i];
		cur[s]=fir[s],cur[t]=fir[t];
		ans+=dfs(s,inf);
	}
	return ans;
}
void solve(int l,int r,vector<int> cur)
{
	if(cur.empty()) return ;
	if(l==r)
	{
		for(int i=0;i<(int)cur.size();i++) ans[cur[i]]=l;
		return ;
	}
	// printf("%d %d : ",l,r),print(cur);
	for(int i=0;i<(int)cur.size();i++) vis[cur[i]]=i;
	int mid=(l+r)/2;
	ss=1;
	for(int i=0;i<(int)cur.size();i++)
	{
		int val=v[cur[i]];
		int v1=abs(val-mid),v2=abs(val-mid-1);
		if(v1<=v2) add(i,t,v2-v1);
		else add(s,i,v1-v2);
	}
	for(int i=0;i<(int)cur.size();i++)
	{
		int u=cur[i];
		for(int j=0;j<(int)G[u].size();j++)
		{
			int v=G[u][j];
			if(vis[v]!=-1) add(vis[u],vis[v],INF);
		}
	}
	dinic(cur.size());
	// cout<<"Passed\n";
	for(int i=0;i<(int)cur.size();i++) fir[i]=0;
	fir[s]=fir[t]=0;
	for(int i=0;i<(int)cur.size();i++) vis[cur[i]]=-1;
	vector<int> L,R;
	for(int i=0;i<(int)cur.size();i++)
	{
		if(!dep[i]) L.pb(cur[i]);
		else R.pb(cur[i]);
	}
	solve(l,mid,L),solve(mid+1,r,R);
}
signed main()
{
	memset(vis,-1,sizeof(vis));
	cin>>n>>m;
	s=n+1,t=n+2;
	for(int i=1;i<=n;i++) v[i]=read();
	for(int i=1;i<=m;i++)
	{
		int u=read(),v=read();
		G[u].pb(v);
	}
	vector<int> v(n);
	for(int i=0;i<n;i++) v[i]=i+1;
	solve(1,inf,v);
	for(int i=1;i<=n;i++) printf("%lld%c",ans[i]," \n"[i==n]);
	return 0;
}