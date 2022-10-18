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
#define N 400005
int n,m,a[N],top[N],id[N];
string s[N];
int gi(int x,int y) {return x*m+y;}
void rev(int id,int &x,int &y) {x=id/m,y=id%m;}
vector<int> G[N],H[N];
int idgr[N];
int dfn[N],low[N],bel[N],vis[N],st[N],tp,dfscnt,comcnt;
void tarjan(int u)
{
	low[u]=dfn[u]=++dfscnt;
	st[++tp]=u,vis[u]=1;
	for(int v:G[u])
	{
		if(!dfn[v]) tarjan(v),low[u]=min(low[u],low[v]);
		else if(vis[v]) low[u]=min(low[u],dfn[v]);
	}
	if(low[u]==dfn[u])
	{
		comcnt++;
		while(1)
		{
			int tmp=st[tp--];
			bel[tmp]=comcnt,vis[tmp]=0;
			if(tmp==u) break;
		}
	}
}
signed main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>s[i];
	for(int i=0;i<m;i++) a[i]=read();
	for(int i=0;i<m;i++) top[i]=-1;
	for(int i=n-1;i>=0;i--)
	{
		for(int j=0;j<m;j++) if(s[i][j]=='#')
		{
			if(j!=0&&s[i][j-1]=='#') G[gi(i,j)].pb(gi(i,j-1));
			if(j!=m-1&&s[i][j+1]=='#') G[gi(i,j)].pb(gi(i,j+1));
			if(i!=0&&s[i-1][j]=='#') G[gi(i,j)].pb(gi(i-1,j));
			for(int k=-1;k<=1;k++)
			{
				int tj=j+k;
				if(tj<0||tj>=m) continue;
				if(top[tj]!=-1) G[gi(i,j)].pb(gi(top[tj],tj));
			}
		}
		for(int j=0;j<m;j++) if(s[i][j]=='#') top[j]=i;
	}
	for(int i=0;i<n*m;i++)
	{
		int x,y; rev(i,x,y);
		if(s[x][y]=='.') continue;
		if(!dfn[i]) tarjan(i);
	}
	for(int i=0;i<n*m;i++)
	{
		int x,y; rev(i,x,y);
		if(s[x][y]=='.') continue;
		for(int v:G[i]) if(bel[i]!=bel[v]) H[bel[i]].pb(bel[v]),idgr[bel[v]]++;
	}
	int ans=0;
	for(int i=1;i<=comcnt;i++) if(!idgr[i]) ans++;
	cout<<ans<<endl;
	return 0;
}