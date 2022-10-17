#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mod = 998244353;
const int N = 720720;
ll fpow(ll a,ll b){ll r=1;for(a%=mod;b;b>>=1){if(b&1)r=r*a%mod;a=a*a%mod;}return r;}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, a, x, y, k, m;
    cin >> n >> a >> x >> y >> k >> m;
    ll ans = 0, sum = 0;
    vector<int> dp(N);
    for(int i = 0; i < n; ++i) {
        sum += a;
        dp[a % N] += 1;
        a = (1ll * a * x + y) % m;
    }
    for(int i = 1; i <= k; ++i) {
        vector<int> ndp(N);
        ll pw = (k == i ? 0 : fpow(n, k - i - 1)) * (k - i) % mod;
        for(int j = 0, p = 0; j < N; ++j, ++p == i ? p = 0 : 0) {
            if(!dp[j]) continue;
            ndp[j] = (ndp[j] + 1ll * dp[j] * (n - 1)) % mod;
            int nj = j - j % i;
            ndp[nj] += dp[j];
            if(ndp[nj] >= mod) ndp[nj] -= mod;
            if(pw && p) ans -= pw * p * dp[j] % mod;
        }
        dp = move(ndp);
    }
    sum %= mod;
    ans += fpow(n, k - 1) * sum % mod * k % mod;
    ans %= mod;
    if(ans < 0) ans += mod;
    cout << ans << '\n';
}