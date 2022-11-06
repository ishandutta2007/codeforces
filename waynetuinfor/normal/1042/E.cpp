#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 5, mod = 998244353;
int a[maxn][maxn], dp[maxn][maxn];
vector<pair<int, int>> v[maxn * maxn];

int fpow(int a, int n) {
    int res = 1;
    for (; n; n >>= 1) {
        if (n & 1) res = res * 1ll * a % mod;
        a = a * 1ll * a % mod;
    }
    return res;
}

int main() {
    int n, m; scanf("%d %d", &n, &m);
    vector<int> ds;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) scanf("%d", &a[i][j]);
        for (int j = 0; j < m; ++j) ds.push_back(a[i][j]);
    }
    sort(ds.begin(), ds.end());
    ds.resize(unique(ds.begin(), ds.end()) - ds.begin());
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int p = lower_bound(ds.begin(), ds.end(), a[i][j]) - ds.begin();
            v[p].emplace_back(i, j);
        }
    }
    int sum = 0, si2 = 0, si = 0, sj2 = 0, sj = 0, prv = 0;
    for (int i = 0; i < ds.size(); ++i) {
        // printf("sum = %d si2 = %d si = %d sj2 = %d sj = %d prv = %d\n", sum, si2, si, sj2, sj, prv);
        for (int j = 0; j < v[i].size(); ++j) {
            int x, y; tie(x, y) = v[i][j];
            dp[x][y] = sum;
            (dp[x][y] += si2) %= mod;
            (dp[x][y] -= 2ll * si * x % mod) %= mod;
            ((dp[x][y] %= mod) += mod) %= mod;
            (dp[x][y] += x * 1ll * x % mod * 1ll * prv % mod) %= mod;
            (dp[x][y] += sj2) %= mod;
            (dp[x][y] -= 2ll * sj * y % mod) %= mod;
            ((dp[x][y] %= mod) += mod) %= mod;
            (dp[x][y] += y * 1ll * y % mod * 1ll * prv % mod) %= mod;
            dp[x][y] = dp[x][y] * 1ll * fpow(prv, mod - 2) % mod;
            // printf("dp[%d][%d] = %d\n", x, y, dp[x][y]);
        }
        for (int j = 0; j < v[i].size(); ++j) {
            int x, y; tie(x, y) = v[i][j];
            (sum += dp[x][y]) %= mod;
            (prv += 1) %= mod;
            (si2 += x * 1ll * x % mod) %= mod;
            (si += x) %= mod;
            (sj2 += y * 1ll * y % mod) %= mod;
            (sj += y) %= mod;
        }
    }
    int r, c; scanf("%d %d", &r, &c);
    --r, --c;
    printf("%d\n", dp[r][c]);
    return 0;
}