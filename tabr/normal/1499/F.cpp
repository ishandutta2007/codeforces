#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

const int mod = 998244353;

inline void add(int &a, int b) {
    a += b;
    if (a >= mod) {
        a -= mod;
    }
}

inline void sub(int &a, int b) {
    a -= b;
    if (a < 0) {
        a += mod;
    }
}

inline int mul(int a, int b) {
    return (int)((long long)a * b % mod);
}

inline int power(int a, long long b) {
    int res = 1;
    while (b > 0) {
        if (b & 1) {
            res = mul(res, a);
        }
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}

inline int inv(int a) {
    a %= mod;
    if (a < 0) {
        a += mod;
    }
    int b = mod, u = 0, v = 1;
    while (a) {
        int t = b / a;
        b -= t * a;
        swap(a, b);
        u -= t * v;
        swap(u, v);
    }
    assert(b == 1);
    if (u < 0) {
        u += mod;
    }
    return u;
}

const int N = 5050;

int dp[N][N];
int suf[N][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        g[x].emplace_back(y);
        g[y].emplace_back(x);
    }
    function<void(int, int)> dfs = [&](int v, int p) {
        vector<int> a;
        dp[v][0] = 1;
        for (int to : g[v]) {
            if (to == p) {
                continue;
            }
            a.emplace_back(to);
            dfs(to, v);
            int t = 0;
            for (int i = 0; i <= k; i++) {
                add(t, dp[to][i]);
            }
            dp[v][0] = mul(dp[v][0], t);
        }
        int m = (int)a.size();
        vector<int> pre(k + 2, 1);
        for (int i = 0; i < m; i++) {
            vector<int> sum(k + 1);
            sum[0] = dp[a[i]][0];
            for (int j = 1; j < k + 1; j++) {
                add(sum[j], (sum[j - 1] + dp[a[i]][j]) % mod);
            }
            suf[a[i]][0] = sum[k];
            for (int j = 1; j < k + 2; j++) {
                add(suf[a[i]][j], (sum[k] + sum[j - 1]) % mod);
            }
        }
        for (int i = m - 2; i >= 0; i--) {
            for (int j = 0; j < k + 2; j++) {
                suf[a[i]][j] = mul(suf[a[i]][j], suf[a[i + 1]][j]);
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < k; j++) {
                int ad = dp[a[i]][j];
                if (i != m - 1) {
                    ad = mul(ad, suf[a[i + 1]][min(j, k - j - 2) + 1]);
                }
                if (i != 0) {
                    ad = mul(ad, pre[min(j - 1, k - j - 2) + 1]);
                }
                add(dp[v][j + 1], ad);
            }
            vector<int> sum(k + 1);
            sum[0] = dp[a[i]][0];
            for (int j = 1; j < k + 1; j++) {
                add(sum[j], (sum[j - 1] + dp[a[i]][j]) % mod);
            }
            pre[0] = mul(pre[0], sum[k]);
            for (int j = 1; j < k + 2; j++) {
                pre[j] = mul(pre[j], (sum[k] + sum[j - 1]) % mod);
            }
        }
    };
    dfs(0, -1);
    int ans = 0;
    for (int i = 0; i <= k; i++) {
        add(ans, dp[0][i]);
    }
    cout << ans << '\n';
    return 0;
}