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
inline char rdchar()
{
	char ch=getchar();
	while(!(ch>='a'&&ch<='z')&&!(ch>='A'&&ch<='Z')&&!(ch>='0'&&ch<='9')) ch=getchar();
	return ch;
}
typedef pair<int,int> pii;
void print(vector<int> x){for(int i=0;i<(int)x.size();i++) printf("%d%c",x[i]," \n"[i==(int)x.size()-1]);}
#define N 505
int a[N][N],f[N][N],w[N][N],n,m;
namespace Flow
{
	struct Edge{int v,cap,nxt;};
	Edge edge[N*N*20];
	int fir[N*10],cur[N*10],ss,dep[N*10];
	inline void init()
	{
		memset(fir,0,sizeof(fir)); ss=1;
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
signed main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) a[i][j]=rdchar()=='B';
	int ans=0;
	for(int i=n;i>=1;i--)
	{
		for(int j=m;j>=1;j--)
		{
			int pre=w[i+1][j]^w[i][j+1]^w[i+1][j+1];
			if(a[i][j]^pre) f[i][j]=1,ans++;
			w[i][j]=pre^f[i][j];
		}
	}
	init();
	s=n+m+1,t=n+m+2;
	for(int i=1;i<n;i++) if(f[i][m]) add(s,i,1);
	for(int i=1;i<m;i++) if(f[n][i]) add(i+n,t,1);
	for(int i=1;i<n;i++) for(int j=1;j<m;j++) if(f[i][j]) add(i,j+n,1);
	int res=dinic();
	ans-=res/2*2;
	if(res%2==1&&f[n][m]) ans-=2;
	cout<<ans<<endl;
	return 0;
}