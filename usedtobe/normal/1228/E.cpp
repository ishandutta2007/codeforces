#include<bits/stdc++.h>
using namespace std;
const int N = 255;
typedef long long ll;
const ll mod = 1e9+7;
ll pw(ll a,ll b){
    b%=mod-1;
    ll an=1;
    for(;b;b>>=1){
        if(b&1)an=an*a%mod;
        a=a*a%mod;
    }
    return an;
}
ll n,K;
ll dp[N][N],C[N][N],pp[N],pp2[N];
int main() {
    cin>>n>>K;
    C[0][0]=1;
    for(int i=1;i<=n;++i){
        C[i][0]=1;
        for(int j=1;j<=i;++j) C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
    }   
    dp[0][0]=1;
    pp[0]=1;
    for(int i=1;i<=n;++i)pp[i]=pp[i-1]*K%mod;
    pp2[0]=1;
    for(int i=1;i<=n;++i)pp2[i]=pp2[i-1]*(K-1)%mod;
    // pw(K,j)
    for(int i=0;i<n;++i){
        for(int j=min(1,i);j<=n;++j)if(dp[i][j]){
            for (int k=0;k<=n-j;++k) {
                (dp[i+1][j+k]+=dp[i][j]*pp[j]%mod*C[n-j][k]%mod*pp2[n-(j+k)]%mod)%=mod;
            }
            (dp[i+1][j]+=mod-pp2[n]*dp[i][j]%mod)%=mod;
        }
    }
    // for (int i=1;i<=n;++i){
    //     for(int j=0;j<=i;++j){
    //         printf("dp[%d][%d]=",i,j);
    //         cout<<dp[i][j]<<endl;
    //     }
    // }
    // cout<<dp[2][1]<<endl;
    cout<<dp[n][n];
    return 0;
}