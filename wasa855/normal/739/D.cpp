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
	char ch=getchar(); int nega=1;
	while(!isdigit(ch))
	{
		if(ch=='?') return -1;
		if(ch=='-') nega=-1;
		ch=getchar();
	}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
#define N 305
namespace Flow
{
#define l qaq
	struct Edge{int v,cap,nxt;};
	Edge edge[N*N*N/20];
	int fir[N*N*3+5],cur[N*N*3+5],ss,dep[N*N*3+5];
	inline void init()
	{
		memset(fir,0,sizeof(fir)); ss=1;
	}
	inline void add(int u,int v,int w)
	{
		// printf("%d %d %d\n",u,v,w);
		edge[++ss]=(Edge){v,w,fir[u]}; fir[u]=ss;
		edge[++ss]=(Edge){u,0,fir[v]}; fir[v]=ss;
	}
	int q[N*10],l,r;
	int s=N*N*3+1,t=N*N*3+2;
	bool bfs()
	{
		memset(dep,0,sizeof(dep));
		dep[s]=1;
		l=1,r=1; q[1]=s;
		while(l<=r)
		{
			int u=q[l++];
			for(int i=fir[u];i!=0;i=edge[i].nxt)
			{
				if(!edge[i].cap) continue;
				int v=edge[i].v;
				if(!dep[v])
				{
					dep[v]=dep[u]+1;
					if(v==t) return 1;
					q[++r]=v;
				}
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
			if(!edge[i].cap) continue;
			int v=edge[i].v;
			if(dep[u]+1!=dep[v]) continue;
			int R=dfs(v,min(flow,edge[i].cap));
			if(R)
			{
				edge[i].cap-=R,edge[i^1].cap+=R;
				go+=R,flow-=R;
			}
		}
		return go;
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
#undef l
};
using namespace Flow;
int d[N],l[N];
vector<pii> a;
vector<pii> v[N];
vector<int> ze[N];
int maxn[N];
int n,cnt;
int id[N][N],vis[N][N];
int nd[N][N],Rev[N],ans[N];
pii rev[N*N];
bool ok[N];
void solve()
{
	for(int i=1;i<=n;i++) v[i].clear();
	for(int i=1;i<=n;i++) ze[i].clear();
	a.clear(); cnt=0;
	memset(maxn,0,sizeof(maxn));
	memset(id,0,sizeof(id));
	memset(vis,0,sizeof(vis));
	memset(nd,0,sizeof(nd));
	memset(Rev,0,sizeof(Rev));
	memset(ans,0,sizeof(ans));
	memset(rev,0,sizeof(rev));
	for(int i=1;i<=n;i++)
	{
		if(l[i]!=-1) v[l[i]].eb(d[i],l[i]);
		if(l[i]!=-1&&d[i]!=-1)
		{
			maxn[l[i]]=max(maxn[l[i]],d[i]),vis[d[i]][l[i]]=1,nd[d[i]][l[i]]=i;
			if(d[i]==0) ze[l[i]].pb(i);
		}
		else a.eb(d[i],l[i]),Rev[a.size()]=i;
	}
	init();
	// for(int i=1;i<=n;i++) printf("%d%c",(int)ze[i].size()," \n"[i==n]);
	for(int i=1;i<=n;i++)
	{
		if(!v[i].size()) continue;
		int r=(i-ze[i].size()%i)%i;
		if(!ze[i].size()) r=i;
		for(int j=1;j<=r;j++)
		{
			cnt++;
			add(s,cnt,1);
			rev[cnt]=mp(0,i);
		}
		for(int j=1;j<=maxn[i];j++)
		{
			if(!vis[j][i]) id[j][i]=++cnt,add(s,id[j][i],1),rev[cnt]=mp(j,i);
		}
	}
	if(cnt>n) return ;
	// for(int i=1;i<=cnt;i++)
	// {
		// auto [d,l]=rev[i];
		// printf("-- %d %d\n",d,l);
	// }
	for(int i=0;i<(int)a.size();i++)
	{
		auto [d,l]=a[i];
		for(int c=1;c<=cnt;c++)
		{
			auto [j,k]=rev[c];
			if(d!=-1&&d!=j) continue;
			if(l!=-1&&l!=k) continue;
			add(c,cnt+i+1,1);
		}
		add(cnt+i+1,t,1);
	}
	int f=dinic();
	if(f!=cnt) return ;
	for(int i=1;i<=cnt;i++)
	{
		auto [D,L]=rev[i];
		for(int j=fir[i];j!=0;j=edge[j].nxt)
		{
			int v=edge[j].v;
			if(v>i&&edge[j].cap==0)
			{
				int id=Rev[v-cnt];
				d[id]=D,l[id]=L;
				nd[D][L]=id;
				if(D==0) ze[L].pb(id);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<(int)ze[i].size();j+=i)
		{
			for(int k=0;k<i-1;k++) ans[ze[i][j+k]]=ze[i][j+k+1];
			ans[ze[i][j+i-1]]=ze[i][j];
		}
	}
	// for(int i=1;i<=n;i++) printf("%d %d\n",d[i],l[i]);
	// return 0;
	int maxid=0;
	for(int i=1;i<=n;i++)
	{
		if(maxn[maxid]<maxn[i]) maxid=i;
	}
	for(int i=1;i<=n;i++)
	{
		if(d[i]==0&&l[i]==-1) ans[i]=i;
	}
	// cout<<maxid<<endl;
	for(int i=1;i<=n;i++)
	{
		if(ans[i]) continue;
		if(d[i]==-1) d[i]=1;
		if(l[i]==-1) l[i]=maxid;
		if(d[i]!=-1&&l[i]!=-1)
		{
			assert(d[i]!=0);
			ans[i]=nd[d[i]-1][l[i]];
		}
	}
	for(int i=1;i<=n;i++) if(!ans[i]) ans[i]=i;
	for(int i=1;i<=n;i++) printf("%d ",ans[i]);
	exit(0);
}
signed main()
{
	// cout<<sizeof(edge)/1024.0/1024.0<<endl;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		d[i]=read(),l[i]=read();
		
	}
	int maxid=0;
	for(int i=1;i<=n;i++)
	{
		if(l[i]==-1&&d[i]>d[maxid]) maxid=i;
	}
	if(!maxid)
	{
		solve();
		cout<<"-1\n";
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		l[maxid]=i;
		solve();
	}
	cout<<"-1\n";
	/*
	int Maxn=0;
	for(int i=1;i<=n;i++)
	{
		if(maxn[i]>maxn[Maxn]) Maxn=i;
	}
	if(l[maxid]==-1&&d[maxid]!=maxn[Maxn])
	{
		l[maxid]=Maxn;
		v[l[maxid]].eb(d[maxid],l[maxid]),maxn[l[maxid]]=max(maxn[l[maxid]],d[maxid]),vis[d[maxid]][l[maxid]]=1,nd[d[maxid]][l[maxid]]=maxid;
	}
	*/
	return 0;
}