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
#define N 100005
int a[N],w[N][105],d[N],n,m,k,s;
vector<int> G[N];
void bfs(vector<int> v)
{
	memset(d,0x3f,sizeof(d));
	queue<int> q;
	for(int i:v) d[i]=0,q.push(i);
	while(!q.empty())
	{
		int u=q.front(); q.pop();
		for(int v:G[u])
		{
			if(d[v]>d[u]+1) d[v]=d[u]+1,q.push(v);
		}
	}
}
signed main()
{
	cin>>n>>m>>k>>s;
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=m;i++)
	{
		int u=read(),v=read();
		G[u].pb(v),G[v].pb(u);
	}
	for(int i=1;i<=k;i++)
	{
		vector<int> f;
		for(int j=1;j<=n;j++) if(a[j]==i) f.pb(j);
		bfs(f);
		for(int j=1;j<=n;j++) w[j][i]=d[j];
	}
	for(int i=1;i<=n;i++)
	{
		sort(w[i]+1,w[i]+1+k);
		int ans=0; for(int j=1;j<=s;j++) ans+=w[i][j];
		printf("%d%c",ans," \n"[i==n]);
	}
	return 0;
}