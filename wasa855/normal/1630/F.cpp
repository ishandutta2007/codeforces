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
void print(vector<int> x){for(int i=0;i<(int)x.size();i++) printf("%d%c",x[i]," \n"[i==(int)x.size()-1]);}
#define N 50005
namespace Flow
{
	struct Edge{int v,cap,nxt;};
	Edge edge[N*400];
	int fir[N*10],cur[N*10],ss,dep[N*10];
	inline void init(int siz)
	{
		// memset(fir,0,sizeof(fir)); ss=1;
		for(int i=0;i<=siz;i++) fir[i]=0;
		ss=1;
	}
	inline void add(int u,int v,int w)
	{
		edge[++ss]=(Edge){v,w,fir[u]}; fir[u]=ss;
		edge[++ss]=(Edge){u,0,fir[v]}; fir[v]=ss;
	}
	int q[N*10],l,r;
	int s,t;
	bool bfs()
	{
		// memset(dep,0,sizeof(dep));
		for(int i=1;i<=t;i++) dep[i]=0;
		int l=1,r=1; q[1]=s,dep[s]=1;
		while(l<=r)
		{
			int u=q[l++];
			for(int i=fir[u];i!=0;i=edge[i].nxt)
			{
				if(!edge[i].cap) continue;
				int v=edge[i].v;
				if(!dep[v]) dep[v]=dep[u]+1,q[++r]=v;
				if(v==t) return dep[t];
			}
		}
		return dep[t];
	}
	int dfs(int u,int flow)
	{
		if(u==t||flow==0) return flow;
		int ans=0;
		for(int &i=cur[u];i!=0;i=edge[i].nxt)
		{
			if(!edge[i].cap) continue;
			int v=edge[i].v;
			if(dep[v]!=dep[u]+1) continue;
			int go=dfs(v,min(flow,edge[i].cap));
			if(go)
			{
				flow-=go,ans+=go;
				edge[i].cap-=go,edge[i^1].cap+=go;
			}
			if(!flow) return ans;
		}
		return ans;
	}
	int dinic()
	{
		int ans=0;
		while(bfs())
		{
			memcpy(cur,fir,sizeof(cur));
			ans+=dfs(s,inf);
		}
		return ans;
	}
};
using namespace Flow;
int a[N],id[N],n;
vector<int> d[N];
void work()
{
	cin>>n;
	for(int i=1;i<=n;i++) a[i]=read(),id[a[i]]=i;
	s=n*4+5,t=n*4+6; init(t);
	for(int i=1;i<=n;i++) add(s,i*4,1),add(i*4+1,i*4+2,1),add(i*4+3,t,1);
	for(int i=1;i<=n;i++)
	{
		for(int j:d[a[i]]) if(id[j]) add(i*4,id[j]*4+1,1),add(i*4+2,id[j]*4+3,1);
	}
	cout<<dinic()<<endl;
	for(int i=1;i<=n;i++) id[a[i]]=0;
}
signed main()
{
	for(int i=1;i<N;i++) for(int j=i+i;j<N;j+=i) d[j].pb(i);
	int T=read(); while(T--) work();
	return 0;
}