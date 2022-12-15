#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MN = 202;
ll dp[MN][MN][MN], N, K, X, i, arr[MN];
ll solve(ll n,ll s,ll rem){
        if(n==N+1) return rem==0? 0:-(1LL<<60);
        else if(dp[n][s][rem]!=-1) return dp[n][s][rem];
        dp[n][s][rem]=-(1LL<<60);
        if(rem){
                if(n+1<=s) dp[n][s][rem]=max(dp[n][s][rem],solve(n+1,s,rem));
                dp[n][s][rem]=max(dp[n][s][rem],solve(n+1,min(N+1,n+K),rem-1)+arr[n]);
        }
        else{
                if(n+1<=s) dp[n][s][rem]=max(dp[n][s][rem],solve(n+1,s,rem));
        }
        return dp[n][s][rem];
}
int main(){
        memset(dp,-1,sizeof(dp));
        for(scanf("%lld%lld%lld",&N,&K,&X),i=1;i<=N;i++)
                scanf("%lld",&arr[i]);
        if(solve(1,K,X)<0) printf("-1\n");
        else printf("%lld\n",solve(1,K,X));
        return 0;
}