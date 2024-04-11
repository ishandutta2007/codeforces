#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 105;
int mod = 1e9+7;
ll comb[maxn][maxn],f[maxn];
void init(int n) {
    f[0]=1;
    for(int i=1;i<=n;++i) f[i]=f[i-1]*i%mod;
    for(int i=0;i<=n;++i) comb[i][0]=1;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=i;++j)
            comb[i][j]=(comb[i-1][j]+comb[i-1][j-1])%mod;
}

ll dp[105][105][105];
ll solve(int n, int m, int k) {
    if(n == 0) return k == 0;
    if(m == 1) {
        if(k == 1) return f[n];
        return 0;
    }
    if(k > n) return 0;
    if(n == 1) return k == 0;
    if(m > n) return k == 0 ? f[n] : 0;
    if(m > n + 1 - k) return 0; // -> m <= n - k + 1
    assert(m <= n - k + 1);
    if(dp[n][m][k] != -1) return dp[n][m][k];
    int ret = 0;
    if(m > 2) {
        for(int i = 0; i <= n - 1; ++i) {
            int tmp = 0;
            for(int j = 0; j <= i; ++j) {
                if(i && i >= m - 1 && m - 2 > i - j) break;
                if(n - 1 - i && n - m >= i && m > n - i - k + j + 1) {
                    j = m - n + i + k - 2;
                    continue;
                }
                tmp = (tmp + 1ll * solve(i, m - 1, j) * solve(n - 1 - i, m - 1, k - j)) % mod;
            }
            ret = (ret + 1ll * tmp * comb[n-1][i]) % mod;
        }
    } else {
        for(int i = 0; i <= n - 1; ++i) {
            int tmp = 0;
            for(int j = 0; j <= i; ++j) {
                tmp = (tmp + 1ll * solve(i, m - 1, j) * solve(n - 1 - i, m - 1, k - j)) % mod;
            }
            ret = (ret + 1ll * tmp * comb[n-1][i]) % mod;
        }
    }
    return dp[n][m][k] = ret;
}
int main() {
    int n, m, k;
    cin >> n >> m >> k >> mod;
    init(101);
    memset(dp, -1, sizeof(dp));
    cout << solve(n, m, k) << '\n';
}