#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 505;
const int mod = 998244353;
char op[maxn];
int a[maxn], f[maxn];
ll dp[maxn][maxn];
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> op[i];
        if(op[i] == '+') cin >> a[i];
    }
    ll ans = 0;
    for(int i = 1; i <= n; ++i) {
        if(op[i] == '-') continue;
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for(int j = 1; j <= n; ++j) {
            if(op[j] == '-') {
                for(int k = 0; k <= n; ++k) {
                    (dp[j][k] += dp[j-1][k]) %= mod;
                }
                for(int k = 0; k <= n; ++k) {
                    (dp[j][k] += dp[j-1][k+1]) %= mod;
                }
                if(j < i) {
                    (dp[j][0] += dp[j-1][0]) %= mod;
                }
            } else {
                if(a[j] < a[i] || (a[j] == a[i] && j < i)) {
                    for(int k = 0; k <= n; ++k) {
                        (dp[j][k+1] += dp[j-1][k]) %= mod;
                    }
                    for(int k = 0; k <= n; ++k) {
                        (dp[j][k] += dp[j-1][k]) %= mod;
                    }
                } else if(j == i) {
                    for(int k = 0; k <= n; ++k) {
                        (dp[j][k] += dp[j-1][k]) %= mod;
                    }
                } else {
                    for(int k = 0; k <= n; ++k) {
                        (dp[j][k] += 2 * dp[j-1][k]) %= mod;
                    }
                }
            }
        }
        for(int j = 0; j <= n; ++j) ans += dp[n][j] * a[i] % mod;
    }
    cout << ans % mod << endl;
}