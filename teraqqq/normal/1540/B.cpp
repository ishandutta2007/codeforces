#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>

using namespace std;
using ll = long long;

const int N = 200;
const int MOD = 1e9+7;

int n, sz[N], par[N], h[N], rev[N+1];
int dp[N][N];
vector<int> g[N];

int get_rev(int a, int m = MOD) {
    return a == 1 ? 1 : m - (ll) m * get_rev(m % a, a) / a;
}

void dfs(int v, int u, int p = -1) {
    par[v] = p;
    if (p < 0) h[v] = 0;
    sz[v] = 1;

    for (int to : g[v]) {
        if (to != p) {
            h[to] = h[v] + 1;
            dfs(to, u, v);
            sz[v] += sz[to];
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    cin >> n;
    for (int i = n; --i; ) {
        int a, b; cin >> a >> b;
        g[a-1].push_back(b-1);
        g[b-1].push_back(a-1);
    }

    for (int i = 1; i <= n; ++i) rev[i] = get_rev(i);
    for (int i = 1; i < n; ++i) dp[0][i] = 1, dp[i][0] = 0;
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < n; ++j) {
            dp[i][j] = (ll) (dp[i-1][j] + dp[i][j-1]) * rev[2] % MOD;
        }
    }

    ll ans = 0;

    int x = 0;
    for (int i = 0; i < n; ++i) {
        dfs(i, i);
        for (int j = i + 1; j < n; ++j) {
            int ds = 0;
            for (int u = j; u != i; u = par[u]) {
                int cur_size = sz[u] - ds;
                ans += (ll) cur_size * rev[n] % MOD * dp[h[j] - h[u]][h[u]] % MOD;
                ds = sz[u];
            }
        }
    }

    cout << ans % MOD << endl;
}