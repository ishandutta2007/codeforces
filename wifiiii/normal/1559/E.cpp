#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 100005;
int prime[maxn],np[maxn],mu[maxn],tot=0;
void init(int n) {
   np[1]=mu[1]=1;
   for(int i=2;i<=n;++i) {
       if(!np[i]) prime[++tot]=i,mu[i]=-1;
       for(int j=1;j<=tot;++j) {
           if(i*prime[j]>n) break;
           if(i%prime[j]==0) {
               np[i*prime[j]]=1;
               mu[i*prime[j]]=0;
               break;
           }
           np[i*prime[j]]=1;
           mu[i*prime[j]]=-mu[i];
       }
   }
}
const int mod = 998244353;
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m;
    cin >> n >> m;
    init(m);
    vector<int> l(n), r(n);
    for(int i = 0; i < n; ++i) cin >> l[i] >> r[i];
    ll ans = 0;
    for(int i = 1; i <= m; ++i) {
        if(!mu[i]) continue;
        int M = m / i;
        vector<ll> dp(M + 1), sdp(M + 1);
        dp[0] = 1;
        for(int j = 0; j < n; ++j) {
            int L = (l[j] + i - 1) / i, R = r[j] / i;
            // ndp[k] = dp[k-R] + ... + dp[k-L]
            //        = sdp[k-L] - sdp[k-R-1]
            partial_sum(dp.begin(), dp.end(), sdp.begin(), [](ll a, ll b) {return (a + b) % mod;});
            for(int k = 0; k <= M; ++k) {
                dp[k] = 0;
                if(k - L >= 0) dp[k] += sdp[k - L];
                if(k - R - 1 >= 0) dp[k] -= sdp[k - R - 1];
                if(dp[k] >= mod) dp[k] -= mod;
                if(dp[k] < 0) dp[k] += mod;
            }
        }
        partial_sum(dp.begin(), dp.end(), sdp.begin(), [](ll a, ll b) {return (a + b) % mod;});
        ans += mu[i] * sdp.back();
    }
    ans %= mod;
    if(ans < 0) ans += mod;
    cout << ans << endl;
}