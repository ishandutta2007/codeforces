#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll tpow[100001];
ll pow2[100001];
ll mod = 1000000007;
ll dp[100001][2];
int main(){
    string s; cin >> s;
    tpow[0] = 1;
    pow2[0] = 1;
    for(int i=1;i<=100000;i++) pow2[i] = (pow2[i-1]*2)%mod;
    for(int i=1;i<=100000;i++) tpow[i] = (tpow[i-1]*10)%mod;
    dp[1][0] = s[0]-'0';
    dp[1][1] = 0;
    ll n = s[0]-'0';
    for(int i=2;i<=s.length();i++){
        dp[i][0] = ((i-1)*1LL*(i)/2+1)%mod*(s[i-1]-'0')+(dp[i-1][0]+dp[i-1][1])*1LL*10%mod;
        dp[i][1] = (n+dp[i-1][1])%mod;
        dp[i][0]%=mod, dp[i][1]%=mod;
        n*=10;
        n+=s[i-1]-'0';
        n%=mod;
    }
    ll ans = dp[s.length()][0]+dp[s.length()][1]-n;
    ans%=mod;
    if(ans<0) ans+=mod;
    cout << ans << endl;


}