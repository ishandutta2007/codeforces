#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int mod;
vector<ll> mul(vector<ll>&a,vector<ll>&b) {
    int sza=a.size(),szb=b.size(),len=sza+szb-1;
    vector<ll> ret(len);
    for(int i=0;i<sza;i++)
        for(int j=0;j<szb;j++)
            (ret[i+j]+=a[i]*b[j]%mod)%=mod;
    return ret;
}
vector<ll> dp[55];
ll ans[55];
int main() {
    int N;
    cin >> N >> mod;
    --N;
    dp[0] = vector<ll>(1, 1);
    for(int i = 1; i <= N; ++i) {
        vector<ll> tmp(i, 1);
        dp[i] = mul(dp[i-1], tmp);
    }
    ans[1] = ans[2] = 0;
    for(int n = 3; n <= N; ++n) {
        ans[n] = ans[n-1] * (n + 1) % mod;
        ll cur = 0;
        for(int i = 0; i <= n; ++i) {
            for(int j = i + 1; j <= n; ++j) {
                int d = j - i;
                ll sum = 0;
                for(int k = d + 1; k < dp[n].size(); ++k) sum += dp[n][k];
                for(int k = 0; sum; ++k) {
                    ans[n] += sum % mod * dp[n][k] % mod;
                    sum -= dp[n][k + d + 1];
                }
            }
        }
        ans[n] %= mod;
        if(ans[n] < 0) ans[n] += mod;
    }
    cout << ans[N] << endl;
}