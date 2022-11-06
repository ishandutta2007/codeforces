#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;
vector<int> dv[maxn];
int dp[maxn], inv[maxn], pv[maxn];
vector<pair<int, int>> pw[maxn];

int fpow(int a, int n) {
    int res = 1;
    while (n > 0) {
        if (n & 1) res = 1ll * res * a % mod;
        a = 1ll * a * a % mod;
        n >>= 1;
    }
    return res;
}

void sieve() {
    vector<int> pr;
    for (int i = 2; i < maxn; ++i) {
        if (!pv[i]) {
            pv[i] = i;
            pr.push_back(i);
        }
        for (int j = 0; i * pr[j] < maxn; ++j) {
            pv[i * pr[j]] = pr[j];
            if (i % pr[j] == 0)
                break;
        }
    }
}

int calc(int a, int b, int m) {
    // return number of 1 <= c <= m
    // such that gcd(a, c) = b
    int target = 1;
    vector<int> eq;
    for (int i = 0, j = 0; i < (int)pw[a].size(); ++i) {
        while (j < (int)pw[b].size() && pw[b][j].first < pw[a][i].first) ++j;
        int x = pw[a][i].second;
        int y = (j < (int)pw[b].size() && pw[b][j].first == pw[a][i].first ? pw[b][j].second : 0);
        target *= fpow(pw[a][i].first, y);
        if (y < x) eq.push_back(pw[a][i].first);
    } 
    int range = m / target;
    int n = (int)eq.size(), res = 0;
    for (int s = 0; s < (1 << n); ++s) {
        int k = 1;
        for (int i = 0; i < n; ++i) {
            if (s >> i & 1)
                k *= eq[i];
        }
        if (__builtin_popcount(s) & 1) res -= range / k;
        else res += range / k;
    } 
    return res;
}

int main() {
    sieve();
    int m; scanf("%d", &m);
    for (int i = 1; i <= m; ++i) {
        for (int j = i + i; j <= m; j += i)
            dv[j].push_back(i);
    }
    for (int i = 1; i <= m; ++i) inv[i] = fpow(i, mod - 2);
    for (int i = 1; i <= m; ++i) {
        for (int j = i; j > 1; ) {
            int cnt = 0, d = pv[j];
            while (j % d == 0) {
                j /= d;
                ++cnt;
            }
            pw[i].emplace_back(d, cnt);
        }
    }
    dp[1] = 0;
    for (int i = 2; i <= m; ++i) {
        for (int j = 0; j < (int)dv[i].size(); ++j) {
            int d = dv[i][j];
            int p = calc(i, d, m) * 1ll * inv[m] % mod;
            dp[i] += p * 1ll * dp[d] % mod;
            if (dp[i] >= mod) dp[i] -= mod;
        }
        dp[i]++;
        int coef = (1 + mod - (m / i) * 1ll * inv[m] % mod) % mod;
        dp[i] = dp[i] * 1ll * fpow(coef, mod - 2) % mod;
    }
    int ans = 0;
    for (int i = 1; i <= m; ++i) {
        ans += 1ll * inv[m] * dp[i] % mod;
        if (ans >= mod) ans -= mod;
    }
    printf("%d\n", 1 + ans);
    return 0;
}