#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e9+7;
map<ll,ll> dp;
ll N, M;
void add(ll &a,ll b){
    a = (a+b)%mod;
}
ll solve(ll n){
    if(n<=1) return 1;
    else if(dp[n]) return dp[n];
    ll m = n>>1, tot = 0;
    add(tot, solve(m-1)*solve(n-m));
    for(ll i=m-M+1;i<=m;i++){
        if(i>=1&&i+M-1<=n)
            add(tot, solve(i-1)*solve(n-(i+M-1)));
    }
    dp[n] = tot;
    return dp[n];
}

int main(){
    scanf("%lld%lld",&N,&M);
    printf("%lld\n",solve(N));
    return 0;
}