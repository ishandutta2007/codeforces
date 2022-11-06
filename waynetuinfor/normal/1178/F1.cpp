#include <bits/stdc++.h>
using namespace std;

const int maxn = 500 + 5;
const int mod = 998244353;
int a[maxn], dp[maxn][maxn];
bool v[maxn][maxn];

int dfs(int l, int r) {
    // printf("l = %d r = %d\n", l, r);
    if (v[l][r]) return dp[l][r];
    if (r - l == 1) return 1;
    if (l >= r) return 1;
    int p = min_element(a + l, a + r) - a;
    int x = 0, y = 0;
    for (int i = p; i >= l; --i) {
        int f = dfs(l, i) * 1ll * dfs(i, p) % mod;
        (x += f) %= mod;
    }
    for (int i = p; i < r; ++i) {
        int f = dfs(p + 1, i + 1) * 1ll * dfs(i + 1, r) % mod;
        (y += f) %= mod;
    }
    dp[l][r] = x * 1ll * y % mod;
    v[l][r] = true;
    // printf("l = %d r = %d x = %d y = %d p = %d\n", l, r, x, y, p);
    // printf("dp[%d][%d] = %d\n", l, r, dp[l][r]);
    return dp[l][r];
}

int main() {
    int n, m; scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]), --a[i];
    printf("%d\n", dfs(0, n));
    return 0;
}