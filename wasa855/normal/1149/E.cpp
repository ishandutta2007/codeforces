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
#define N 200005
int dep[N],val[N],dgr[N],vis[N],sum[N],n,m;
vector<int> G[N],rG[N],to[N];
int mex(vector<int> v)
{
	int n=v.size();
	for(int i=0;i<=n;i++) vis[i]=0;
	for(int i:v) vis[i]=1;
	for(int i=0;i<=n;i++) if(!vis[i]) return i;
	assert(0);
}
signed main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) val[i]=read();
	for(int i=1;i<=m;i++)
	{
		int u=read(),v=read();
		G[u].pb(v),rG[v].pb(u),dgr[u]++;
	}
	queue<int> q;
	for(int i=1;i<=n;i++) if(!dgr[i]) q.push(i);
	while(!q.empty())
	{
		int u=q.front(); q.pop();
		dep[u]=mex(to[u]);
		for(int v:rG[u])
		{
			to[v].pb(dep[u]);
			if(!--dgr[v]) q.push(v);
		}
	}
	for(int i=1;i<=n;i++) sum[dep[i]]^=val[i];
	int maxn=-1;
	for(int i=0;i<=n;i++) if(sum[i]) maxn=i;
	if(maxn==-1) return cout<<"LOSE\n",0;
	int pos=0;
	for(int i=1;i<=n;i++) if(dep[i]==maxn&&(val[i]^sum[maxn])<val[i]) pos=i;
	val[pos]^=sum[maxn];
	for(int v:G[pos]) val[v]^=sum[dep[v]],sum[dep[v]]=0;
	cout<<"WIN\n";
	for(int i=1;i<=n;i++) printf("%d%c",val[i]," \n"[i==n]);
	return 0;
}