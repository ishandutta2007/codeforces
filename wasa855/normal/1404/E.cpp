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
#define N 205
char st[N][N];
int a[N][N],b[N][N];
int n,m;
namespace Flow
{
	struct Edge{int v,cap,nxt;};
	Edge edge[N*N*16];
	int fir[N*N*2],cur[N*N*2],ss,dep[N*N*2];
	int s=N*N*2-1,t=N*N*2-2;
	inline void init()
	{
		memset(fir,0,sizeof(fir)); ss=1;
	}
	inline void add(int u,int v,int w)
	{
//		printf("%d %d %d\n",u,v,w);
		edge[++ss]=(Edge){v,w,fir[u]}; fir[u]=ss;
		edge[++ss]=(Edge){u,0,fir[v]}; fir[v]=ss;
	}
	int q[N*N*2],l,r;
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
				flow-=R,go+=R;
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
};
using namespace Flow;
int getid(int x,int y,int ty)
{
	if(ty) return n*(m-1)+(x-1)*m+y;
	else return (x-1)*(m-1)+y;
}
bool valid(int x,int y,int ty)
{
	if(ty) return x>=1&&x<n&&y>=1&&y<=m;
	else return x>=1&&x<=n&&y>=1&&y<m;
}
signed main()
{
	cin>>n>>m; init();
	for(int i=1;i<=n;i++) scanf("%s",st[i]+1);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<m;j++) a[i][j]=(st[i][j]=='.'||st[i][j+1]=='.');
	}
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<=m;j++) b[i][j]=(st[i][j]=='.'||st[i+1][j]=='.');
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<m;j++)
		{
			if(!a[i][j]) add(s,getid(i,j,0),1);
		}
	}
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(!b[i][j]) add(getid(i,j,1),t,1);
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<m;j++)
		{
			if(!a[i][j])
			{
				for(int c=-1;c<=0;c++) for(int d=0;d<=1;d++)
				{
					int x=i+c,y=j+d;
					if(valid(x,y,1)&&!b[x][y]) add(getid(i,j,0),getid(x,y,1),10);
				}
			}
		}
	}
	int tot=0;
	for(int i=1;i<=n;i++) for(int j=1;j<m;j++) tot+=(!a[i][j]);
	for(int i=1;i<n;i++) for(int j=1;j<=m;j++) tot+=(!b[i][j]);
	tot=dinic()-tot;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) tot+=(st[i][j]=='#');
	cout<<tot<<endl;
	return 0;
}