#include<bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(int)(n);++i)
using namespace std;

const int maxn=17;
const int maxm=20007;
const int INF=1e9;

int n,m,mat[maxn][maxm];
int d1[maxn][maxn],d2[maxn][maxn],dp[2<<maxn][maxn],ans=0;
int main(){
	scanf("%d%d",&n,&m);
	rep(i,n) rep(j,m) scanf("%d",&mat[i][j]);
	rep(i,n) rep(j,n) d1[i][j]=d2[i][j]=INF;
	rep(i,n) rep(j,n) rep(k,m) d1[i][j]=min(d1[i][j],abs(mat[i][k]-mat[j][k]));
	rep(i,n) rep(j,n) rep(k,m-1) d2[i][j]=min(d2[i][j],abs(mat[i][k]-mat[j][k+1]));
	rep(i,n){
		memset(dp,0,sizeof(dp));
		dp[1<<i][i]=INF;
		rep(j,1<<n) rep(k,n) rep(u,n) if (!(j>>k&1))dp[j|(1<<k)][k]=max(dp[j|(1<<k)][k],min(dp[j][u],d1[u][k]));
		int t=0;
		rep(j,n) ans=max(ans,min(dp[(1<<n)-1][j],d2[j][i]));
	}
	printf("%d\n",ans);
	return 0;
}