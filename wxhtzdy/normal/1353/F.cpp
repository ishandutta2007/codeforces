#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=105;
int n,m;
ll a[N][N];
ll Calc(ll x){
    ll dp[n][m];
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)dp[i][j]=(ll)1e18;
    if(a[0][0]<x)return 1e18;
    dp[0][0]=a[0][0]-x;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]<(x+i+j))continue;
            if(i>0)dp[i][j]=min(dp[i][j],dp[i-1][j]+a[i][j]-x-i-j);
            if(j>0)dp[i][j]=min(dp[i][j],dp[i][j-1]+a[i][j]-x-i-j);
        }
    }
    return dp[n-1][m-1];
}
int main(){
    int t;
    scanf("%i",&t);
    while(t--){
        scanf("%i %i",&n,&m);
        for(int i=0;i<n;i++)for(int j=0;j<m;j++)scanf("%lld",&a[i][j]);
        ll ans=1e18;
        for(int i=0;i<n;i++)for(int j=0;j<m;j++){
            //printf("%lld\n",Calc(a[i][j]-i-j));
            ans=min(ans,Calc(a[i][j]-i-j));
        }
        printf("%lld\n",ans);
    }
    return 0;
}