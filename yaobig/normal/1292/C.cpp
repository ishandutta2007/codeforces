#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 3000
#define mod 1000000007
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

int nxt[maxn+5][maxn+5],sz[maxn+5][maxn+5];
vi e[maxn+5];
int rt;

void dfs(int now,int fa,int from)
{
	sz[rt][now]=1;
	if(from!=0) nxt[rt][now]=from;
	for(auto v: e[now]) if(v!=fa)
	{
		dfs(v,now,from?from:v);
		sz[rt][now]+=sz[rt][v];
	}
}

int n; 
ll dp[maxn+5][maxn+5];
ll cal(int i,int j)
{
	if(i>j) swap(i,j);
	if(i==j) return 0;
	if(dp[i][j]!=-1) return dp[i][j];
	ll tmp=0;
	int j1=nxt[j][i];
	int i1=nxt[i][j];
	tmp=max(cal(i,j1),cal(i1,j))+1ll*(n-sz[i][i1])*(n-sz[j][j1]);
	return dp[i][j]=tmp;
}

int main()
{
	scanf("%d",&n);
	rep(i,1,n-1)
	{
		int x,y; scanf("%d%d",&x,&y); 
		e[x].pb(y);
		e[y].pb(x);
	}
	rep(i,1,n) rt=i,dfs(i,0,0);
	memset(dp,-1,sizeof dp);
	ll ans=0;
	rep(i,1,n) rep(j,i+1,n) ans=max(ans,cal(i,j));
	printf("%I64d\n",ans);
	return 0;
}