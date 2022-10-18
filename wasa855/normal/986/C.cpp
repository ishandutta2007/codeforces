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
#define N (1<<22)
int n,m;
bitset<N> vis,h;
// vector<int> G[N];
struct Edge{int v,nxt;};
Edge edge[N];
int fir[N],ss;
void add(int u,int v)
{
	edge[++ss]=(Edge){v,fir[u]};
	fir[u]=ss;
}
void dfs(int u)
{
	if(vis[u]) return ;
	vis[u]=1;
	for(int i=fir[u];i!=0;i=edge[i].nxt) dfs(edge[i].v);
	for(int i=0;i<n;i++) if(u>>i&1) dfs(u^(1<<i));
}
signed main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int t=read(); h[t]=1;
		add(t,((1<<n)-1)^t);
	}
	int ans=0;
	for(int i=0;i<1<<n;i++) if(h[i]&&!vis[i]) dfs(i),ans++;
	cout<<ans<<endl;
	return 0;
}