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
#define N 205
namespace Flow
{
	struct Edge{int v,cap,nxt;};
	Edge edge[N*N*14];
	int ss=1,fir[N*N],cur[N*N],s,t;
	void init(int _s,int _t)
	{
		s=_s,t=_t,ss=1;
		memset(fir,0,sizeof(fir));
	}
	void add(int u,int v,int w)
	{
//		printf("%d %d %d\n",u,v,w);
		edge[++ss]=(Edge){v,w,fir[u]}; fir[u]=ss;
		edge[++ss]=(Edge){u,0,fir[v]}; fir[v]=ss;
	}
	int dep[N*N],q[N*N];
	bool bfs()
	{
		memset(dep,0,sizeof(dep));
		int l=1,r=1; q[1]=s,dep[s]=1;
		while(l<=r)
		{
			int u=q[l++];
			for(int i=fir[u];i!=0;i=edge[i].nxt)
			{
				if(!edge[i].cap) continue;
				int v=edge[i].v;
				if(!dep[v]) dep[v]=dep[u]+1,q[++r]=v;
				if(v==t) return 1;
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
	int dinic(int _s,int _t)
	{
		s=_s,t=_t; int ans=0;
		while(bfs())
		{
			memcpy(cur,fir,sizeof(cur));
			ans+=dfs(s,inf);
		}
		return ans;
	}
};
using namespace Flow;
int a[N][N],id[N*4],eid[N][N],n,m,cnt,tim;
int dx[]={1,-1,0,0},dy[]={0,0,1,-1};
ll ans=0;
int getid(int x,int y) {return (x-1)*m+y;}
bool valid(int x,int y) {return 1<=x&&x<=n&&1<=y&&y<=m;}
signed main()
{
	cin>>n; m=n;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
	{
		a[i][j]=read();
		if(a[i][j]>=1) id[++cnt]=a[i][j];
	}
	sort(id+1,id+cnt+1); int siz=unique(id+1,id+cnt+1)-id-1;
	vector<pii> nd;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if(a[i][j]==0) nd.eb(i,j);
	int curflow=0;
	int s=n*m+1,t=n*m+2;
	for(int j=1;j<=n;j++) for(int k=1;k<=m;k++)
	{
		if(a[j][k]==-1) continue;
		for(int t=0;t<4;t++)
		{
			int tx=j+dx[t],ty=k+dy[t];
			if(!valid(tx,ty)) continue;
			if(a[tx][ty]!=-1) add(getid(j,k),getid(tx,ty),1);
		}
		if(a[j][k]!=0) eid[j][k]=ss+1,add(getid(j,k),t,inf);
	}
	int tmp=n*m+3; int qwq=ss+1; add(tmp,0,0);
	for(int i=1;i<siz;i++)
	{
		for(int j=1;j<=n;j++) for(int k=1;k<=m;k++)
		{
			if(a[j][k]==id[i])
			{
				int ed=eid[j][k];
				if(edge[ed^1].cap)
				{
					curflow-=edge[ed^1].cap;
					edge[qwq].v=getid(j,k),edge[qwq].cap=edge[ed^1].cap;
					edge[qwq^1].v=tmp,edge[qwq^1].cap=0;
					assert(dinic(tmp,getid(j,k))==edge[ed^1].cap);
				}
				edge[ed].cap=edge[ed^1].cap=0;
				add(s,getid(j,k),inf);
			}
		}
		int r=dinic(s,t);
		curflow+=r;
		ans+=1LL*curflow*(id[i+1]-id[i]);
	}
	cout<<ans<<endl;
	return 0;
}