#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MN = 2005;
int dp[MN][MN], n, m, k, i, j, a[MN], b[MN];
int solve(int i,int j){
        if(i==n+1) return 0;
        else if(j==m+1) return 1LL<<60;
        else if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j]=min(solve(i,j+1),max(solve(i+1,j+1),abs(b[j]-a[i])+abs(b[j]-k)));
}
signed main(){
        memset(dp,-1,sizeof(dp));
        for(scanf("%d%d%d",&n,&m,&k),i=1;i<=n;i++)
                scanf("%d",&a[i]);
        for(i=1;i<=m;i++)
                scanf("%d",&b[i]);
        dp[0][0]=0;
        sort(b+1,b+m+1);
        sort(a+1,a+n+1);
        printf("%lld\n",solve(1,1));
        return 0;
}