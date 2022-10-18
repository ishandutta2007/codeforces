#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
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
inline int min(int x,int y,int z){return min(x,min(y,z));}
inline int max(int x,int y,int z){return max(x,max(y,z));}
inline int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
inline int add(int x,int y,int z){return add(add(x,y),z);}
inline int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
inline int mul(int x,int y){return 1LL*x*y%mod;}
inline int mul(int x,int y,int z){return mul(mul(x,y),z);}
#define N 300005
int u[N],v[N],n,m;
vector<int> G[N];
int f[N],dgr[N];
void solve(int u,int v,int w)
{
	for(int x:G[v])
	{
		if(dgr[x]==1) return ;
	}
	f[u]+=w;
}
void topo()
{
	queue<int> q; int tot=0;
	for(int i=1;i<=n;i++) if(!dgr[i]) q.push(i),tot++;
	while(!q.empty())
	{
		int u=q.front(); q.pop();
		if(!q.size()) f[u]+=n-tot;
		if(q.size()==1) solve(u,q.front(),n-tot);
		for(int v:G[u])
		{
			dgr[v]--;
			if(!dgr[v]) q.push(v),tot++;
		}
	}
}
signed main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		u[i]=read(),v[i]=read();
		G[u[i]].pb(v[i]); dgr[v[i]]++;
	}
	topo();
	for(int i=1;i<=n;i++) dgr[i]=0,G[i].clear();
	for(int i=1;i<=m;i++)
	{
		G[v[i]].pb(u[i]);
		dgr[u[i]]++;
	}
	topo();
	int ans=0;
	for(int i=1;i<=n;i++) ans+=f[i]>=n-2;
	cout<<ans<<endl;
	return 0;
}