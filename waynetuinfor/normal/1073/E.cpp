#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;
pair<int, int> dp[70][1024];
bool v[70][1024];
int tp[70];

pair<int, int> dfs(int x, int mask, int k) {
    if (x == 0) {
        if (__builtin_popcount(mask) <= k) return make_pair(1, 0);
        else return make_pair(0, 0);
    }
    if (v[x][mask]) return dp[x][mask];
    dp[x][mask] = make_pair(0, 0);
    for (int i = 0; i < 10; ++i) {
        int tmask = (mask || i ? (mask | (1 << i)) : 0);
        pair<int, int> p = dfs(x - 1, tmask, k);
        (dp[x][mask].first += p.first) %= mod;
        (dp[x][mask].second += i * 1ll * tp[x - 1] % mod * p.first % mod) %= mod;
        (dp[x][mask].second += p.second) %= mod;
    }
    v[x][mask] = true;
    return dp[x][mask];
}

int check(long long x, int k) {
    long long y = x;
    int mask = 0;
    while (y) {
        mask |= (1 << (y % 10));
        y /= 10;
    }
    if (__builtin_popcount(mask) <= k) return x % mod;
    return 0;
}

int solve(long long x, int k) {
    vector<int> d;
    int res = check(x, k);
    while (x) {
        d.push_back(x % 10);
        x /= 10;
    }
    reverse(d.begin(), d.end());
    int mask = 0, prv = 0;
    for (int i = 0; i < (int)d.size(); ++i) {
        for (int j = 0; j < d[i]; ++j) {
            int tmask = (mask | (1 << j));
            if (mask == 0 && j == 0) tmask = 0;
            int tprv = (prv + j * 1ll * tp[d.size() - i - 1] % mod) % mod;
            pair<int, int> p = dfs(d.size() - i - 1, tmask, k);
            (res += (p.second + p.first * 1ll * tprv % mod) % mod) %= mod;
        } 
        mask |= (1 << d[i]);
        (prv += d[i] * 1ll * tp[d.size() - i - 1] % mod) %= mod;
        if (__builtin_popcount(mask) > k) break;
    }
    return res;
}

int main() {
    tp[0] = 1;
    for (int i = 1; i < 70; ++i) tp[i] = tp[i - 1] * 10ll % mod;
    long long l, r; int k;
    scanf("%lld%lld%d", &l, &r, &k);
    printf("%d\n", (solve(r, k) + mod - solve(l - 1, k)) % mod);
}