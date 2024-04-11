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
#define N 800005
struct Edge{int v,col,nxt;};
Edge edge[N*2];
int fir[N],ss;
vector<int> col[N];
int n,m,cnt,low[N],dfn[N],fa[N],fe[N],dfscnt;
void addedge(int u,int v,int w)
{
	edge[++ss]=(Edge){v,w,fir[u]}; fir[u]=ss;
	edge[++ss]=(Edge){u,w,fir[v]}; fir[v]=ss;
}
void getcir(int u,int v,int _w)
{
	cnt++; col[cnt].pb(_w);
	while(u!=v)
	{
		int e=fe[u];
		col[cnt].pb(edge[e].col);
		u=fa[u];
	}
}
void tarjan(int u,int f)
{
	fa[u]=f,low[u]=dfn[u]=++dfscnt;
	for(int i=fir[u];i!=0;i=edge[i].nxt)
	{
		int v=edge[i].v;
		if(v==f) continue;
		if(!dfn[v]) fe[v]=i,tarjan(v,u),low[u]=min(low[u],low[v]);
		else low[u]=min(low[u],dfn[v]);
		if(low[v]>dfn[u]) cnt++,col[cnt].pb(edge[i].col),col[cnt].pb(edge[i].col);
	}
	for(int i=fir[u];i!=0;i=edge[i].nxt)
	{
		int v=edge[i].v;
		if(dfn[v]<dfn[u]&&v!=f) getcir(u,v,edge[i].col);
	}
}
int Fa[N],u[N],v[N],w[N],t[N],siz[N];
int find(int u) {return Fa[u]==u?u:Fa[u]=find(Fa[u]);}
set<int> s[N];
vector<int> bel[N],nd[N];
signed main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++) u[i]=read(),v[i]=read(),w[i]=t[i]=read();
	sort(t+1,t+m+1); int qwq=unique(t+1,t+m+1)-t-1;
	for(int i=1;i<=m;i++) w[i]=lower_bound(t+1,t+qwq+1,w[i])-t;
	for(int i=1;i<=m;i++) addedge(u[i],v[i],w[i]);
	for(int i=1;i<=n;i++) if(!dfn[i]) tarjan(i,0);
//	cout<<cnt<<endl;
//	for(int i=1;i<=cnt;i++) print(col[i]);
	for(int i=1;i<=cnt;i++) for(int j:col[i]) bel[j].pb(i);
	for(int i=1;i<=cnt;i++) Fa[i]=i;
	for(int i=1;i<=qwq;i++)
	{
		for(int j=1;j<(int)bel[i].size();j++) Fa[find(bel[i][j-1])]=find(bel[i][j]);
	}
	for(int i=1;i<=cnt;i++) nd[find(i)].pb(find(i)),siz[find(i)]+=col[i].size();
	for(int i=1;i<=cnt;i++) for(int j:col[i]) s[find(i)].insert(j);
	int ans=0;
	for(int i=1;i<=cnt;i++) if(find(i)==i)
	{
		int r=min((int)s[i].size(),siz[i]-(int)nd[i].size());
		ans+=r;
	}
	cout<<ans<<endl;
	return 0;
}