#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
const int maxn = 1e4;
vector<long long> dd[maxn];
map<long long, int> pos;
int dp[100][maxn], inv[maxn];

int fpow(int x, int n) {
    int res = 1;
    while (n) {
        if (n & 1) res = res * 1ll * x % mod;
        x = x * 1ll * x % mod;
        n >>= 1;
    }
    return res;
}

int main() {
    long long n; int k; scanf("%lld%d", &n, &k);
    vector<pair<long long, int>> dv;
    long long x = n;
    for (long long i = 2; i * i <= n; ++i) {
        int c = 0;
        while (x % i == 0) {
            x /= i;
            ++c;
        } 
        if (c > 0) dv.emplace_back(i, c);
    }
    if (x > 1) dv.emplace_back(x, 1);
    for (int i = 1; i < maxn; ++i) inv[i] = fpow(i, mod - 2);
    int ans = 1;
    for (int i = 0; i < (int)dv.size(); ++i) {
        int cnt = dv[i].second;
        for (int j = 0; j <= k; ++j) {
            for (int r = 0; r <= cnt; ++r) {
                dp[r][j] = 0;
            }
        }
        dp[cnt][0] = 1;
        for (int j = 1; j <= k; ++j) {
            int sum = 0;
            for (int p = 0; p <= cnt; ++p) {
                sum += dp[p][j - 1] * 1ll * inv[p + 1] % mod;
                sum %= mod;
            }
            for (int r = 0; r <= cnt; ++r) {
                dp[r][j] = sum;
                sum -= dp[r][j - 1] * 1ll * inv[r + 1] % mod;
                sum += mod;
                sum %= mod;
            }
        }
        int e = 0;
        long long x = 1;
        for (int j = 0; j <= cnt; ++j) {
            e += dp[j][k] * 1ll * (x % mod) % mod;
            e %= mod;
            x *= dv[i].first;
        }
        ans = ans * 1ll * e % mod;
    }
    printf("%d\n", ans);
}