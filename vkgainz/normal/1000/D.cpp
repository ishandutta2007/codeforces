#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll mod = 998244353;
ll dp[2000];
ll choose[1001][1001];
ll fact[1001];
ll inv(ll b,ll p){
    if(p==0) return 1;
    ll x = inv(b,p/2);
    if(p%2){
        return (((x*x%mod)*b+mod)%mod);
    }
    else return ((x*x)%mod+mod)%mod;
}
ll get(int a,int b){
    ll x = fact[a];
    ll y = fact[a-b];
    ll z = fact[b];
    return (x*inv(y,mod-2)%mod*inv(z,mod-2)%mod)%mod;
}
int main(){
    int n; cin >> n;
    int a[n];
    for(int i=0;i<n;i++) cin >> a[i];
    fact[0] = 1;
    for(int i=1;i<=1000;i++) fact[i] = (fact[i-1]*i)%mod;
    for(int i=0;i<=1000;i++){
        for(int j=0;j<=1000;j++){
            choose[i][j] = get(i,j);
        }
    }
    for(int i=n-1;i>=0;i--){
        
        for(int j=i+1;j<n;j++){
            if(a[i]<=j-i && a[i]>0){
                dp[i]+=(1+dp[j+1])*1LL*choose[j-i-1][a[i]-1];
                dp[i]%=mod;
            }
        }
        dp[i]+=dp[i+1];
        dp[i]%=mod;
    }
    if(dp[0]<0) dp[0]+=mod;
    cout << dp[0] << endl;
}