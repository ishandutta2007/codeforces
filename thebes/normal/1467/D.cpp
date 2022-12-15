#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;

const int MN = 5005, MM = 2e5+5, mod = 1e9+7;
int N, K, Q, i, x, y, arr[MN], cnt[MN], dp[MN][MN], ans;

int main(){
    scanf("%d%d%d",&N,&K,&Q);
    for(i=1;i<=N;i++) scanf("%d",&arr[i]);
    for(i=1;i<=N;i++)
        dp[0][i] = 1;
    for(int j=1;j<=K;j++){
        for(i=1;i<=N;i++){
            if(i>1) dp[j][i] = (dp[j][i]+dp[j-1][i-1])%mod;
            if(i<N) dp[j][i] = (dp[j][i]+dp[j-1][i+1])%mod;
        }
    }
    for(i=1;i<=N;i++){
        for(int j=0;j<=K;j++){
            cnt[i] = (1LL*cnt[i]+1LL*dp[j][i]*dp[K-j][i])%mod;
        }
    }
    for(i=1;i<=N;i++)
        ans = (1LL*ans+1LL*arr[i]*cnt[i])%mod;
    for(;Q;Q--){
        scanf("%d%d",&x,&y);
        ans = (1LL*ans-1LL*arr[x]*cnt[x])%mod;
        if(ans<0) ans += mod;
        arr[x] = y;
        ans = (1LL*ans+1LL*arr[x]*cnt[x])%mod;
        printf("%d\n",ans);
    }
    return 0;
}