#include <bits/stdc++.h>

using namespace std;

const int maxN = 19;

int n, m, a[maxN][maxN];
long long dp[1<<maxN][maxN];

int getBit(int mask, int i) {return (mask>>i)&1;}

long long Count(int s) {
    memset(dp, 0, sizeof dp);

    dp[1<<s][s] = 1;
    for(int mask = 1; mask < (1<<n); ++mask) {
        for(int u = s; u < n; ++u) {
            if (dp[mask][u]) {
                for(int v = s; v < n; ++v)
                    if (a[u][v] && !getBit(mask, v))
                        dp[mask|(1<<v)][v] += dp[mask][u];
            }
        }
    }

    long long res = 0;
    for(int v = s; v < n; ++v) {
        if (a[s][v]) {
            for(int mask = 1; mask < (1<<n); ++mask)
                res += dp[mask][v];
        }
    }

    return res;
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        a[u][v] = a[v][u] = 1;
    }

    long long ans = 0;
    for(int u = 0; u < n; ++u)
        ans += Count(u);
    cout << (ans-m)/2;

    return 0;
}