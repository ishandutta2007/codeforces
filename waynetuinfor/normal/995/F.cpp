#include <bits/stdc++.h>
using namespace std;

const int maxn = 3000 + 5, mod = 1e9 + 7;
vector<int> g[maxn];
long long dp[maxn][maxn];
int n, d;

void dfs(int x, int p) {
    for (int i = 0; i <= n; ++i) dp[x][i] = 1;
    for (int u : g[x]) if (u != p) {
        dfs(u, x);
        for (int i = 0; i <= n; ++i) (dp[x][i] *= dp[u][i]) %= mod;
    }
    for (int i = 1; i <= n; ++i) (dp[x][i] += dp[x][i - 1]) %= mod;
}

long long fpow(long long a, long long n) {
    (a += mod) %= mod;
    (n += mod - 1) %= mod - 1;
    long long r = 1;
    for (; n; n >>= 1) {
        if (n & 1) (r *= a) %= mod;
        (a *= a) %= mod;
    }
    return r;
}

namespace lagrange {
    long long pf[maxn], nf[maxn];
    long long ipf[maxn], inf[maxn];
    void init() {
        pf[0] = nf[0] = 1;
        ipf[0] = inf[0] = 1;
        for (int i = 1; i < maxn; ++i) {
            pf[i] = pf[i - 1] * i % mod;
            nf[i] = nf[i - 1] * (mod - i) % mod;
            ipf[i] = fpow(pf[i], -1);
            inf[i] = fpow(nf[i], -1);
        }
    } 
    long long solve(int n, vector<long long> y, long long x) {
        if (x <= n) return y[x];
        long long all = 1;
        for (int i = 0; i <= n; ++i) (all *= (x - i + mod)) %= mod;
        long long ans = 0;
        for (int i = 0; i <= n; ++i) {
            long long z = all * fpow(x - i, -1) % mod;
            long long l = pf[i], r = nf[n - i];
            (ans += y[i] * z % mod * fpow(l * r, -1)) %= mod;
        }
        return ans;
    }
}

int main() {
    scanf("%d %d", &n, &d);
    for (int i = 1; i < n; ++i) {
        int p; scanf("%d", &p); --p;
        g[p].push_back(i);
        g[i].push_back(p);
    }
    dfs(0, -1);
    vector<long long> v;
    for (int i = 0; i <= n; ++i) v.push_back(dp[0][i]);
    lagrange::init();
    printf("%lld\n", lagrange::solve(n, v, d - 1));
}