#include <bits/stdc++.h>
using namespace std;

const int MN = 360360;
typedef long long ll;
ll dp[MN+1], a, b, k, lol, dp2[MN+1];
ll solve(ll st,ll en){
    memset(dp2,0,sizeof(dp2));
    for(ll i=st+1;i<=en;i++){
        dp2[i-st]=1LL<<60;
        for(int j=2;j<=k;j++){
            ll nxt = i%j;
            if(nxt>0&&i-nxt>=st) dp2[i-st]=min(dp2[i-st],1+dp2[i-nxt-st]);
        }
        dp2[i-st]=min(dp2[i-st],1+dp2[i-1-st]);
    }
    return dp2[en-st];
}
int main(){
    scanf("%lld%lld%lld",&b,&a,&k);
    for(int i=1;i<=MN;i++){
        dp[i] = 1LL<<60;
        for(int j=2;j<=k;j++){
            ll nxt = i%j;
            if(nxt>0) dp[i]=min(dp[i],1+dp[i-nxt]);
        }
        dp[i]=min(dp[i],1+dp[i-1]);
    }
    lol = dp[MN];
    ll l = ceil(a/(long double)MN);
    ll r = floor(b/(long double)MN);
    if(l>r){
        printf("%lld\n",solve(a,b));
    }
    else{
        ll ans = (r-l)*lol;
        ans += solve(r*MN,b)+solve(a,l*MN);
        printf("%lld\n",ans);
    }
    return 0;
}