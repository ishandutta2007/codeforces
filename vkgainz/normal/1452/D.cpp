#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define f first
#define s second
const int MX = 1e6+5;
long long mod = 998244353;
long long inv(int b, int p) {
    if(p==0) return 1LL;
    long long x = inv(b, p/2);
    if(p%2) return (((x*1LL*x)%mod*1LL*b)%mod+mod)%mod;
    else return ((x*1LL*x)%mod+mod)%mod;
}
int main() {
    int n; cin >> n;
    //dp[i] = 1/2*dp[i-1]+1/4*dp[i-2]
    long long dp[200001];
    long long a = inv(2, mod-2), b = inv(4, mod-2);
    dp[1] = a, dp[2] = b;
    for(int i=3;i<=n;i++) {
        dp[i] = a*1LL*dp[i-1]+b*1LL*dp[i-2];
        dp[i]%=mod;
    }
    cout << dp[n] << "\n";
}