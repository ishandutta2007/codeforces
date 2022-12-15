#include <bits/stdc++.h>
using namespace std;

const int MN=505,mod=998244353;
int dp[2][MN][MN], dp2[2][MN][MN], N, M, K, i, j, k, ans, cnt[MN], cnt2[MN];
inline void add(int&x,int y){x=(x+y)%mod;}
signed main(){
    scanf("%d%d",&N,&M); K=N;
    dp[1][1][1]=2; dp2[1][1][1]=1;
    for(i=1;i<N;i++){
        for(j=1;j<=K;j++){for(k=1;k<=K;k++)dp[(i+1)%2][j][k]=dp2[(i+1)%2][j][k]=0;}
        for(j=1;j<=K;j++){
            for(k=1;k<=j;k++){
                int x = dp[i%2][j][k], y = dp2[i%2][j][k];
                if(k+1<=K) {
                    add(dp[(i+1)%2][max(j,k+1)][k+1],x);
                    add(dp2[(i+1)%2][max(j,k+1)][k+1],y);
                }
                add(dp[(i+1)%2][j][1],x);
                add(dp2[(i+1)%2][j][1],y);
            }
        }
    }
    for(i=1;i<=K;i++){
        for(j=1;j<=i;j++){
            add(cnt[i],dp[N%2][i][j]);
            add(cnt2[i],dp2[N%2][i][j]);
        }
    }
    for(i=1;i<=K;i++){
        for(j=1;i*j<M&&j<=K;j++)
            add(ans,(1LL*cnt[i]*cnt2[j])%mod);
    }
    printf("%d\n",ans);
    return 0;
}