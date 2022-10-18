#include<bits/stdc++.h>
using namespace std;
#define pb push_back
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
inline int min(int x,int y,int z){return min(x,min(y,z));}
inline int max(int x,int y,int z){return max(x,max(y,z));}
inline int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
inline int add(int x,int y,int z){return add(add(x,y),z);}
inline int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
inline int mul(int x,int y){return 1LL*x*y%mod;}
inline int mul(int x,int y,int z){return mul(mul(x,y),z);}
#define N 5005
vector<int> G[N];
int fa[N],f[N][N],fr[N][N],col[N],cnt[N],siz[N],ans[N];
vector<int> ned;
vector<int> bel[N];
int find(int u){return fa[u]==u?u:fa[u]=find(fa[u]);}
signed main()
{
	int n,m;
	cin>>n>>m;
	int a,b,c; cin>>a>>b>>c;
	for(int i=1;i<=n;i++) fa[i]=i,col[i]=-1;
	for(int i=1;i<=m;i++)
	{
		int u=read(),v=read();
		G[u].pb(v),G[v].pb(u);
		fa[find(u)]=find(v);
	}
	for(int i=1;i<=n;i++)
	{
		if(col[i]!=-1) continue;
		queue<int> q; q.push(i); col[i]=1;
		while(!q.empty())
		{
			int u=q.front(); q.pop();
			for(int v:G[u])
			{
				if(col[v]==-1) col[v]=col[u]^1,q.push(v);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int v:G[i])
		{
			if(col[i]==col[v]) {cout<<"NO\n";return 0;}
		}
	}
	ned.pb(0);
	for(int i=1;i<=n;i++)
	{
		int u=find(i);
		siz[u]++;
		if(col[i]) cnt[u]++;
		bel[u].pb(i);
		if(u==i) ned.pb(i);
	}
	f[0][0]=1;
	for(int i=1;i<(int)ned.size();i++)
	{
		for(int j=0;j<=n;j++)
		{
			if(f[i-1][j])
			{
				f[i][j+cnt[ned[i]]]=1; fr[i][j+cnt[ned[i]]]=0;
				f[i][j+siz[ned[i]]-cnt[ned[i]]]=1; fr[i][j+siz[ned[i]]-cnt[ned[i]]]=1;
			}
		}
	}
	if(f[ned.size()-1][b]==1)
	{
		cout<<"YES\n";
		int cur=b;
		for(int i=(int)ned.size()-1;i>=1;i--)
		{
			if(fr[i][cur]==0)
			{
				for(int j:bel[ned[i]])
				{
					// printf("%d %d\n",j,col[j]);
					ans[j]=col[j];
				}
				cur-=cnt[ned[i]];
			}
			else
			{
				for(int j:bel[ned[i]])
				{
					// printf("%d %d\n",j,col[j]^1);
					ans[j]=col[j]^1;
				}
				cur-=siz[ned[i]]-cnt[ned[i]];
			}
		}
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(ans[i]==1) printf("2");
			else
			{
				if(cnt==a) printf("3");
				else printf("1"),cnt++;
			}
		}
	}
	else cout<<"NO\n";
	return 0;
}