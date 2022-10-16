#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 5000
#define mod 1000000007
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

vi e[maxn+5];
int deg[maxn+5];
int dp[maxn+5][maxn+5][2];

int dfs(int now,int fa)
{
	if(deg[now]==1) 
	{
		dp[now][0][0]=0;
		dp[now][1][1]=0;
		return 1;
	}
	dp[now][0][0]=0;
	dp[now][0][1]=0;
	int SZ=0;
	for(auto v: e[now]) if(v!=fa)
	{
		int sz=dfs(v,now);
		SZ+=sz;
		per(i,0,SZ) rep(c1,0,1)
		{
			int tmp=inf;
			rep(j,0,sz) rep(c2,0,1) tmp=min(tmp,dp[now][i-j][c1]+dp[v][j][c2]+(c1!=c2));
			dp[now][i][c1]=tmp;
			//printf("? %d, %d %d: %d\n",now,i,c1,dp[now][i][c1]);
		}
	}
	return SZ;
}

int main()
{
	memset(dp,63,sizeof dp);

	int n; scanf("%d",&n);
	rep(i,1,n-1)
	{
		int x,y; scanf("%d%d",&x,&y);
		e[x].pb(y); deg[x]++;
		e[y].pb(x); deg[y]++;
	}
	int N=0;
	rep(i,1,n) if(deg[i]==1) N++;
	if(n==2) return puts("0"),0;
	int rt=-1; rep(i,1,n) if(deg[i]!=1) rt=i;
	dfs(rt,0);
	printf("%d\n",min(dp[rt][N/2][0],dp[rt][N/2][1]));
	return 0;
}