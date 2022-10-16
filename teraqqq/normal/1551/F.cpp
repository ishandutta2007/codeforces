#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

const int N = 101;
const int MOD = 1e9+7;

vector<int> g[N];
int cnt[N][N], dp[N][N];

void calc(int v, int p, int h, int i) {
    cnt[i][h] += 1;
    for (int to : g[v]) {
        if (to != p) {
            calc(to, v, h+1, i);
        }
    }
}

void solve() {
    int n, k; cin >> n >> k;
    for (int i = 1; i <= n; ++i) g[i].clear();

    for (int i = 1; i < n; ++i) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    int ans = 0;
    for (int v = 1; v <= n; ++v) {
        const int c = g[v].size();
        for (int i = 0; i < c; ++i) {
            fill(cnt[i], cnt[i]+n, 0);
            calc(g[v][i], v, 0, i);
        }

        for (int h = 0; h < n; ++h) {
            dp[0][0] = 1;
            for (int j = 0; j < c; ++j) {
                dp[j+1][0] = 1;
                for (int u = 1; u <= k; ++u) {
                    dp[j+1][u] = ((ll) dp[j][u-1] * cnt[j][h] + dp[j][u]) % MOD;
                }
            }

            ans += dp[c][k];
            if (ans >= MOD) ans -= MOD;
        }
    }
    
    if (k == 2) {
        ans = (ll) n * (n - 1) / 2;
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}