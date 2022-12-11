#include<bits/stdc++.h>
using namespace std;
const int N=1e2+5;
int t,n,a[N],b[N],dp[N][N*N],sum[N];
int main(){
    scanf("%d",&t);
    while(t--){
        long long tot=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            tot+=a[i]*a[i]*(n-2);
        }
        for(int i=1;i<=n;i++){
            scanf("%d",&b[i]);
            tot+=b[i]*b[i]*(n-2);
            sum[i]=sum[i-1]+a[i]+b[i];
        }
        for(int i=0;i<=n;i++){
            for(int o=0;o<=10000;o++){
                dp[i][o]=1e9;
            }
        }
        dp[0][0]=0;
        for(int i=1;i<=n;i++){
            for(int o=0;o<=10000;o++){
                if(o>=a[i])dp[i][o]=min(dp[i][o],dp[i-1][o-a[i]]+a[i]*(o-a[i])+o*a[i]+b[i]*(sum[i-1]-o+a[i])+b[i]*(sum[i]-o));
                if(o>=b[i])dp[i][o]=min(dp[i][o],dp[i-1][o-b[i]]+b[i]*(o-b[i])+o*b[i]+a[i]*(sum[i-1]-o+b[i])+a[i]*(sum[i]-o));
            }
        }
        long long ans=1e18;
        for(int i=0;i<=10000;i++)ans=min(ans,1ll*dp[n][i]);
        printf("%lld\n",ans+tot);
    }
    return  0;
}