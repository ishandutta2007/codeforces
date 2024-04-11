#include <bits/stdc++.h>
using namespace std;
typedef __int64 LL;
const LL INF=1e14;
const int N=1e2+10;
int n,m,K;
int a[N];
LL p[N][N];
LL dp[N][N][N];
int main(){
    scanf("%d%d%d",&n,&m,&K);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%I64d",&p[i][j]);
    if(K>n){
        puts("-1");
        return 0;
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            for(int k=0;k<=n;k++)
                dp[i][j][k]=INF;
    if(!a[1]){
        for(int i=1;i<=m;i++)
            dp[1][i][1]=p[1][i];
    }
    else	dp[1][a[1]][1]=0;
    for(int i=2;i<=n;i++){
        if(!a[i]){
            for(int j=1;j<=m;j++)
                for(int k=1;k<=i;k++)
                    for(int h=1;h<=m;h++){
                        if(j==h)
                            dp[i][j][k]=min(dp[i][j][k],dp[i-1][h][k]+p[i][j]);
                        else
                            dp[i][j][k]=min(dp[i][j][k],dp[i-1][h][k-1]+p[i][j]);
                    }
        }
        else{
            for(int k=1;k<=i;k++)
                for(int h=1;h<=m;h++){
                    if(a[i]==h)
                        dp[i][a[i]][k]=min(dp[i][a[i]][k],dp[i-1][a[i]][k]);
                    else
                        dp[i][a[i]][k]=min(dp[i][a[i]][k],dp[i-1][h][k-1]);
                }
        }
    }
    LL ans=INF;
    for(int i=1;i<=m;i++)	ans=min(dp[n][i][K],ans);
	printf("%I64d\n",(ans==INF)?-1:ans);
    return 0;
}